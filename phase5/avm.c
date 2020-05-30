#include "avm.h"
#include "table.h"
unsigned currLine = 0;
unsigned pc = 0;
unsigned char executionFinished = 0;
unsigned totalActuals = 0;
unsigned codeSize = 0;
instruction* code = (instruction*) 0;
unsigned currCode = 0;
avm_memcell ax;
avm_memcell bx;
avm_memcell cx;
avm_memcell retval;

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

void init_code(unsigned size) {
     code = (instruction*) malloc(sizeof(instruction)* size);
     currCode = 0;
     codeSize = size;
}

void emit_code (instruction t) {
     instruction* temp = code + currCode++;
     temp->opcode = t.opcode;
     temp->arg1 = t.arg1;
     temp->arg2 = t.arg2;
     temp->result = t.result;
}

void print_operand(vmarg arg) {
     switch (arg.type) {
          case label_a        : printf("%d, %d ", arg.type, arg.val); break;
          case global_a       : printf("%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case formal_a       : printf("%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case local_a        : printf("%d, %d:%s ", arg.type, arg.val, arg.id); break; 
          case number_a       : printf("%d,%d:%f ", arg.type, arg.val, numConsts[arg.val]); break;
          case string_a       : printf("%d,%d:%s ", arg.type, arg.val, stringConsts[arg.val]); break;
          case bool_a         : printf("%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case nil_a          : printf("%d ", arg.type); break;
          case userfunc_a     : printf("%d, %d:%s ", arg.type, arg.val, userFuncs[arg.val].id); break;
          case libfunc_a      : printf("%d, %d:%s ", arg.type, arg.val, namedLibfuncs[arg.val]); break;
          case retval_a       : printf("%d ", arg.type) ; break;
     }
}

void print_code () {
     for (int i = 0; i < codeSize; i++) {
          printf("%d", code[i].opcode);
          print_operand(code[i].result);
          print_operand(code[i].arg1);
          print_operand(code[i].arg2);
          printf("\n");
     }
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
     switch(arg->type){
          /*Variables*/
          case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
          case local_a: return &stack[topsp-arg->val];
          case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
          case retval_a: return &retval;
          case number_a: {
               reg->type = number_m;
               //reg->data.numVal = consts_getnumber(arg->val); kati prepei na mpei edw
               return reg;
          }
          case string_a: {
               reg->type = string_m;
               reg->data.strVal = strdup(const_getstring(arg->val));
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
     else if(pc == AVM_ENDING_PC ){
          executionFinished = 1;
          return;
     }
     else{
          assert(pc < AVM_ENDING_PC );
          instruction* instr = code + pc;
          assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
          if (instr-> srcLine) currLine = instr->srcLine;
          unsigned oldPC = pc;
          (*executeFuncs[instr->opcode])(instr);
          if (pc == oldPC) ++pc;
     }
}

double consts_getnumber (unsigned int index);



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


unsigned avm_get_envvalue (unsigned i ){
     assert(stack[i].type == number_m);
     unsigned val = (unsigned) stack[i].data.numVal;
     assert((stack[i].data.numVal) == ((double) val));
     return val;
}

void execute_pusharg(instruction* instr){
     avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
     assert(arg);
     avm_assign(&stack[top], arg);
     ++totalActuals;
     avm_dec_top();
}

unsigned char avm_tobool (avm_memcell* m){
     assert(m->type >= 0 && m->type < undef_m);
     return (*toboolFuncs[m->type]) (m);
}

void avm_warning(char* war){
     printf("Warning: %s", war);
}

void avm_error(char* err){
     printf("Error: %s", err);
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

void execute_assign (instruction* instr) {
     avm_memcell* lv = avm_translate_operand(&instr->result , (avm_memcell*)0);
     avm_memcell* rv = avm_translate_operand(&instr->arg1 , &ax);

     assert(lv && ( &stack[AVM_STACKSIZE-1] <= lv && lv > &stack[top] || lv==&retval));
     assert(rv); //should do similar assertion tests here

     avm_assign(lv,rv);
}
void execute_add(instruction* t) {

}
void execute_sub(instruction* t) {

}
void execute_mul(instruction* t) {

}
void execute_div(instruction* t) {

}
void execute_mod(instruction* t) {

}
void execute_uminus(instruction* t) {

}
void execute_and(instruction* t) {

}
void execute_or(instruction* t) {

}
void execute_not(instruction* t) {

}
void execute_jeq(instruction* instr){
  assert(instr->result.type == label_a);

	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
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
void execute_jne(instruction* t) {

}
void execute_jle(instruction* t) {

}
void execute_jge(instruction* t) {

}
void execute_jlt(instruction* t) {

}
void execute_jgt(instruction* t) {

}
void execute_call(instruction* t ) {

}
void execute_funcenter(instruction* t) {

}
void execute_funcexit(instruction* t) {

}

void execute_nop(instruction* t){
     
}

// void avm_initialize(){
//   avm_initstack();
//   avm_registerlibfunc("print", libfunc_print);
//   avm_registerlibfunc("input", libfunc_input);
//   avm_registerlibfunc("objectmemberkyes", libfunc_objectmemberkyes);
//   avm_registerlibfunc("objectotslmembers", libfunc_objectotslmembers);
//   avm_registerlibfunc("objectcopy", libfunc_objectcopy);
//   avm_registerlibfunc("totalarguments", libfunc_totalarguments);
//   avm_registerlibfunc("argument", libfunc_argument);
//   avm_registerlibfunc("typeof", libfunc_typeof);
//   avm_registerlibfunc("strtonum", libfunc_strtonum);
//   avm_registerlibfunc("sqrt", libfunc_sqrt);
//   avm_registerlibfunc("cos", libfunc_cos);
//   avm_registerlibfunc("sin", libfunc_sin);
// }

