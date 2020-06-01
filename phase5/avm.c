#include "avm.h"

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
     for (int i=0; i < size; i++) {
          code[i].arg1.type = nil_a;
          code[i].arg2.type = nil_a;
          code[i].result.type = nil_a;
     }
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
     char* str = (char*) malloc(sizeof(char)*50);
     switch (arg.type) {
          case label_a        : sprintf(str, "%d, %d ", arg.type, arg.val); break;
          case global_a       : sprintf(str, "%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case formal_a       : sprintf(str, "%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case local_a        : sprintf(str, "%d, %d:%s ", arg.type, arg.val, arg.id); break; 
          case number_a       : sprintf(str, "%d, %d:%f ", arg.type, arg.val, numConsts[arg.val]); break;
          case string_a       : sprintf(str, "%d, %d:%s ", arg.type, arg.val, stringConsts[arg.val]); break;
          case bool_a         : sprintf(str, "%d, %d:%s ", arg.type, arg.val, arg.id); break;
          case nil_a          : sprintf(str, "%d ", arg.type); break;
          case userfunc_a     : sprintf(str, "%d, %d:%s ", arg.type, arg.val, userFuncs[arg.val].id); break;
          case libfunc_a      : sprintf(str, "%d, %d:%s ", arg.type, arg.val, namedLibfuncs[arg.val]); break;
          case retval_a       : sprintf(str, "%d ", arg.type) ; break;
          default             : assert(0);
     }
     printf("|%-20s", str);
}

void print_stack() {
     for (int i = AVM_STACKSIZE-1; stack[i].type != undef_m; i--) {
          printf("%d: %f\n", i, stack[i].data.numVal);
     }
}

void print_code () {
     char* op_array[] = {
          "assign",           "add",              "sub",
          "mul",              "div",              "mod",
          "uminus",           "and",              "or",
          "not",              "jeq",              "jne",
          "jle",              "jge",              "jlt",
          "jqt",              "call",             "pusharg",
          "funcenter",        "funcexit",         "newtable",
          "tablegetelem",     "tablesetelem",     "jump",
          "nop"     
     };
     for (int i = 0; i < codeSize; i++) {
          printf("%-2d %-30s", i, op_array[code[i].opcode]);
          print_operand(code[i].result);
          print_operand(code[i].arg1);
          print_operand(code[i].arg2);
          printf("\n");
     }
     printf("-----------------------------------------\n");
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
     switch(arg->type){
          /*Variables*/
          case global_a: return &stack[AVM_STACKSIZE-1-arg->val]; 
          case local_a:  return &stack[topsp-arg->val];
          case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
          case retval_a: return &retval;
          case number_a: {
               reg->type = number_m;
               reg->data.numVal = numConsts[arg->val];
               return reg;
          }
          case string_a: {
               reg->type = string_m;
               reg->data.strVal = strdup(stringConsts[arg->val]);
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
     else {
          assert(pc < AVM_ENDING_PC );
          instruction* instr = code + pc;
          assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
          if (instr-> srcLine) {
               currLine = instr->srcLine;
          }
          unsigned oldPC = pc;
          (*executeFuncs[instr->opcode])(instr);
          if (pc == oldPC) {
               ++pc;
          }
          execute_cycle();
     }
}

void avm_warning(char* war){
     printf("Warning: %s", war);
}

void avm_error(char* err, void *content) {
     executionFinished = 1;
     printf(err, content);
}

void avm_assign (avm_memcell* lv, avm_memcell* rv){
     if (lv == rv) return;
     if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) {
          return;
     }
     if (rv->type == undef_m) {
          avm_warning("assigning from 'undef' content!");
     }
     avm_memcellclear(lv);
     memcpy(lv , rv , sizeof(avm_memcell));
     if (lv->type == string_m) lv->data.strVal= strdup(rv->data.strVal);
     else if (lv->type == table_m) avm_tableincrefcounter(lv->data.tableVal);
}

void execute_assign (instruction* instr) {
     avm_memcell* lv = avm_translate_operand(&instr->result , (avm_memcell*)0);
     avm_memcell* rv = avm_translate_operand(&instr->arg1 , &ax);
     //printf("ARG1 %s %f  RESULT %s %f \n",instr->result.id, lv->data.numVal ,instr->arg1.id ,rv->data.numVal);
     assert(lv);
     //assert(&stack[AVM_STACKSIZE-1] <= lv);
     //assert(lv > &stack[top] || lv == &retval);
     //assert(lv && ( &stack[AVM_STACKSIZE-1] <= lv && lv > &stack[top] || lv == &retval));
     //assert(rv && ( &stack[AVM_STACKSIZE-1] <= rv && lv > &stack[top] || rv == &retval));

     avm_assign(lv,rv);
}

void execute_uminus(instruction* t){}
void execute_and(instruction* t) {}
void execute_or(instruction* t) {}
void execute_not(instruction* t) {}

void execute_jeq(instruction* instr){
     assert(instr->result.type == label_a);

     avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
     unsigned char result = 0;

     if (rv1->type == undef_m || rv2->type == undef_m) {
          avm_error("'Undef' involved in equality!", "");
	}
     else if(rv1->type == nil_m || rv2->type == nil_m) {
		result = (rv1->type == nil_m) && (rv2->type == nil_m);
	}
     else if(rv1->type == bool_m || rv2->type == bool_m) {
		result=rv1->data.boolVal == rv2->data.boolVal;
	} 
     else if(rv1->type !=rv2->type) {
		avm_error("String is illegal!", "");
	}
     else {
          printf("NATALIA\n");
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

void execute_nop(instruction* t){
     
}

// void avm_initialize() {
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

