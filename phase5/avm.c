#include "avm.h"

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
  switch(arg->type){
    /*Variables*/
    case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
    case local_a: return &stack[topsp-arg->val];
    case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
    case retval_a: return &retval;
    case number_a: {
      reg->type = number_m;
      reg->data.numVal = consts_getnumber(arg->val);
      return reg;
    }
    case string_a: {
      reg->type = string_m;
      reg->data.strVal = strdup(consts_getstring(arg->val));
      return reg;
    }
    case bool_a: {
      reg->type = bool_m;
      reg->data.boolVal = arg->val;
      return reg;
    }
    case nil_a: reg->type = nil_m; return reg;
    case userfunc_a: {
      reg->type = userfunc_m;
      reg->data.funcVal = arg->val; /*Address already stored*/
      return reg;
    }
    case libfunc_a: {
      reg->type = libfunc_m;
      reg->data.libfuncVal = libfuncs_getused(arg->val);
      return reg;
    }
    default: assert (0);
  }
}

void execute_cycle(void) {
  if(executionFinished) return;
  else if(pc == AVM_ENDING_PC){
      executionFinished = 1;
      return;
    }
    else{
      assert(pc< AVM_ENDING_PC);
      instruction* instr = code + pc;
      assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
      if (instr-> srcLine) currLine = instr->srcLine;
      unsigned oldPC = pc;
      (*executeFuncs[instr->opcode])(instr);
      if (pc == olsPC) ++pc;
    }
  }

void avm_memcellclear (avm_memcell* m){
  if (m->type != undef_m){
    memclear_func_t f = memclearFuncs[m->type];
    if (f){
      (*f)(m);
      m->type = undef_m;
    }
  }
}

extern void memclear_string(avm_memcell* m){
  assert (m->data.strVal);
  free(m->data.strVal);
}

extern void memclear_table (avm_memcell* m){
  assert (m->data.tableVal);
  avm_tabledecrefcounter(m->data.tableVal);
}

void execute_assign (instruction* instr) {
  avm_memcell* lv = avm_translate_operand(&instr->result , (avm-memcell*)0);
  avm_memcell* rv = avm_translate_operand(&instr->arg1 , &ax);

  assert(lv && ( &stack[N-1] <= lv && lv > $stack[top] || lv==&retval));
  assert(rv); //should do similar assertion tests here

  avm_assign(lv,rv);
}

void avm_assign (avm_memcell* lv, avm_memcell* rv){
  if (lv==rv) return;
  if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) return;
  if (rv->type == undef_m) avm_warning("assigning from 'undef' content!");
  avm_memcellclear(lv);
  memcpy(lv , rv , sizeof(avm_memcell));
  if (lv->type == string_m) lv->data.strVal= strdup(rv->data.strVal);
  else if (lv->type == table_m) avm_tableincrefcounter(lv->data.tableVal);
}

void execute_call (instruction* instr){
  avm_memcell* func = avm_translate_operand(&instr->result , &ax);
  assert(func);
  avm_callsaveenviroment();
  switch (func->type) {
    case userfunc_m: {
      pc=func->data.funcVal;
      assert(pc < AVM_ENDING_PC);
      assert (code[pc].opcode == funcenter_v);
      break;
    }
    case string_m: avm_calllibfunc(func->data.strVal); break;
    case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
    default: {
      char* s = avm_tostring(func);
      avm_error("call: cannot bind '%s' to function!" , s);
      free(s);
      executionFinished=1;
    }
  }
}

void avm_dec_top (void){
  if(!top){/*stack overflow*/
    avm_error("stack overflow");
    executionFinished = 1;
  }
  else --top;
}

void avm_push_envvalue (unsigned val){
  stack[top].type = number_m;
  stack[top].data.numVal = val;
  avm_dec_top();
}

void avm_callsaveenviroment (void) {
  avm_push_envvalue(totalActuals);
  avm_push_envvalue(pc+1);
  avm_push_envvalue(top + totalActuals +2);
  avm_push_envvalue (topsp);
}

void execute_funcenter(instruction* instr){
  avm_memcell* funcInfo = avm_getfuncinfo(pc);
  topsp = top;
  top = top - funcInfo->localSize;
}

unsigned avm_get_envvalue (unsigned i ){
  assert(stack[i].type = number_m);
  unsigned val = (unsigned) stack[i].data.numVal;
  assert (stack[i].data.numVal) == ((double) val);
  return val;
}

void execute_funcexit (instruction* unused) {
  unsigned oldTop = top;
  top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
  pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
  topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

  while (++oldTop <= top){ /*Intetionally ignoring first*/
    avm_memcellclear(&stack[oldTop]);
  }
}

void avm_calllibfunc (char* id){
  library_func_t f = avm_getlibraryfunc(id);
  if (!if) {
    avm_error("unsupported lib func 's' called!" , id);
    executionFinished=1;
  }
  else{/*Notice that enter function and exit function are called manually!*/
    topsp = top;
    totalActuals = 0;
    (*f)();
    if (!executionFinished) execute_funcexit((instruction*) 0);
  }
}

unsigned avm_totalactuals (void) {
  return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i) {
  assert(i < avm_totalactuals());
  return &stack[topsp + AVM_STACKENV_SIZE +1 +i];
}

void libfunc_print(void){
  unsigned n= avm_totalactuals();
  for (unsigned i = 0; i < n; ++i) {
    char* s=avm_tostring(avm_getactual(i));
    puts(s);
    free(s);
  }
}
void execute_pusharg(instruction* instr){
  avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
  assert(arg);
  avm_assign(&stack[top], arg);
  ++totalActuals;
  avm_dec_top();
}

double add_impl( double x, double y ){return x+y;}

double sub_impl( double x, double y ){return x-y;}

double mul_impl( double x, double y ){return x*y;}

double div_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return x/y;
}

double mod_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return (( unsigned ) x ) % (( unsigned ) y );
}

void execute_addrithmetic(instruction* instr){
  avm_memcell* lv = avm_translate_operand(instr->result,(avm_memcell*)0);
	avm_memcell* rv1= avm_translate_operand(instr->arg1,&ax);
	avm_memcell* rv2= avm_translate_operand(instr->arg2,&bx);

  assert(lv && ( (&stack[AVM_STACKSIZE]>= lv && &stack[top]<lv )|| lv==&retval ));
	assert(rv1 && rv2);

  if (rv1->type !=number_m || rv2->type !=number_m ){
		avm_error("not a number arithmetic!\n");
		executionFinished=1;
	}
	else{
		arithmetic_func_t op=arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal,rv2->data.numVal);
	}
}



unsigned char number_tobool (avm_memcell* m){ return m->data.numVal != 0;}
unsigned char string_tobool (avm_memcell* m){ return m->data.strVal != 0;}
unsigned char bool_tobool(avm_memcell* m){ return m->data.boolVal != 0;}
unsigned char table_tobool(avm_memcell* m){ return 1;}
unsigned char userfunc_tobool(avm_memcell* m){ return 1;}
unsigned char libfunc_tobool(avm_memcell* m){ return 1;}
unsigned char nil_tobool(avm_memcell* m){ return 0;}
unsigned char undef_tobool(avm_memcell* m){ assert(0); return 0;}

tobool_func_t toboolFuncs[]={
  number_tobool,
  string_tobool,
  bool_tobool,
  table_tobool,
  userfunc_tobool,
  libfunc_tobool,
  nil_tobool,
  undef_tobool
}

unsigned char avm_tobool (avm_memcell* m){
  assert(m->type >= 0 && m->type < undef_m);
  return (*toboolFuncs[m->type]) (m);
}

void execute_jeq(instruction* instr){
  assert(instr->result->type == label_a);

	avm_memcell* rv1 = avm_translate_operand(instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(instr->arg2, &bx);
  unsigned char result = 0;

  if (rv1->type == undef_m || rv2->type == undef_m){
		avm_error("'Undef' involved in equality!");
	}else if(rv1->type == nil_m || rv2->type == nil_m){
		result = (rv1->type == nil_m) && (rv2->type == nil_m);
	}else if(rv1->type == bool_m || rv2->type == bool_m){
		result=rv1->data.boolVal == rv2->data.boolVal;
	}else if(rv1->type !=rv2->type){
		avm_error("String is illegal!");
	}else{
    //kati tha to broume
  }

  if(!executionFinished && result){
    pc = instr->result.val;
  }
}

void libfunc_typeof (void) {
    unsigned n = avm_totalactuals();
    if(n !=1) avm_error ("one argument (not %d) expected in 'typeof'!", n);
    else {
      avm_memcellclear(&retval);
      retval.type = string_m;
      retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void execute_newtable(instruction* instr){
  avm_memcell* lv = avm_translate_operand(&instr->resulr, (avm_memcell*)0);
  assert(lv && (&stack[AVM_STACKSIZE] >= lv && lv > &stack[top] || lv = &retval));
  avm_memcellclear(lv);
  lv->type = table_m;
  lv->data.tableVal = avm_tablenew();
  avm_tableincrefcounter(lv->data.tableVal);
}



void execute_tablegetelem(instruction* instr){
  avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
  avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*) 0);
  avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

  assert(lv && &stack[N-1] >= lv && lv > &stack[top] || lv==&retval);
  assert(t && &stack[N-1] >= t && t > &stack[top]);
  assert(i);

  avm_memcellclear(lv);
  lv->type = nil_m;

  if (t->type !=table_m){
    avm_error("illegal use of type %s as table!" , typeStrings[t->type]);
  }
  else{
    avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
    if(content) avm_assign(lv , content);
    else {
      char* ts = avm_tostring(t);
      char* is = avm_tostring(i);
      avm_warning("%s[%s] not found!" , ts ,is);
      free(ts);
      free(is);
    }
  }
}


void execute_tablesetelem(instruction* instr){
  avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*)0);
  avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
  avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);
  assert(t && &stack[AVM_STACKSIZE] >= t && t > &stack[top]);
  assert(i && c);
  if(t->type != table_m){
    avm_error("illegal use of type %s as table", typeStrings[t->type]);
  }else{
    avm_tablesetelem(t->data.tableVal, i, c);
  }
}

void avm_initialize(){
  avm_initstack();
  avm_registerlibfunc("print", libfunc_print);
  avm_registerlibfunc("input", libfunc_input);
  avm_registerlibfunc("objectmemberkyes", libfunc_objectmemberkyes);
  avm_registerlibfunc("objectotslmembers", libfunc_objectotslmembers);
  avm_registerlibfunc("objectcopy", libfunc_objectcopy);
  avm_registerlibfunc("totalarguments", libfunc_totalarguments);
  avm_registerlibfunc("argument", libfunc_argument);
  avm_registerlibfunc("typeof", libfunc_typeof);
  avm_registerlibfunc("strtonum", libfunc_strtonum);
  avm_registerlibfunc("sqrt", libfunc_sqrt);
  avm_registerlibfunc("cos", libfunc_cos);
  avm_registerlibfunc("sin", libfunc_sin);
}

void libfunc_totalarguments(){
  unsigned p_topsp = avm_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
  avm_memcellclear(&retval);
  if(!p_topsp){
    avm_error("'totalarguments' called outside a function!");
    retval.type = nil_m;
  }else{
    retval.type = number_m;
    retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
  }
}
