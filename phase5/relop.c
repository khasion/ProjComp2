#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

tostring_func_t tostringFuncs[]={
	number_tostring,
	strng_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

tobool_func_t toboolFuncs[]={
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool,
	avm_tobool
};

unsigned char number_tobool (avm_memcell* m){ return m->data.numVal != 0;}
unsigned char string_tobool (avm_memcell* m){ return m->data.strVal != 0;}
unsigned char bool_tobool(avm_memcell* m){ return m->data.boolVal != 0;}
unsigned char table_tobool(avm_memcell* m){ return 1;}
unsigned char userfunc_tobool(avm_memcell* m){ return 1;}
unsigned char libfunc_tobool(avm_memcell* m){ return 1;}
unsigned char nil_tobool(avm_memcell* m){ return 0;}
unsigned char undef_tobool(avm_memcell* m){ assert(0); return 0;}

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