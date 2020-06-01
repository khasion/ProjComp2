 #include "relop.h"

cmp_func_t cmpFuncs[] = {
	avm_eq,
	avm_neq,
	avm_lt,
	avm_gt,
	avm_gte,
	avm_lte
};

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

tobool_func_t toboolFuncs[]= {
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

char* number_tostring(avm_memcell* param){
	char* buff;
	buff = (char*) malloc(sizeof(char)*100);
	sprintf(buff,"%f",param->data.numVal);
	return buff;
}
char* strng_tostring(avm_memcell* param) {
	char* str;
	str = (char*) malloc(sizeof(param->data.strVal));
	sprintf(str,"%s",param->data.strVal);
	return str;

}
char* bool_tostring(avm_memcell* param){
	char* str;
	str = (char*) malloc(sizeof(char));
	sprintf(str,"%s",param->data.strVal);
	return str;
}
char* table_tostring(avm_memcell* param){ return "1";}
char* userfunc_tostring(avm_memcell* param){ return "1";}
char* libfunc_tostring(avm_memcell* param){ return "1";}
char* nil_tostring(avm_memcell* param) { return "0";}
char* undef_tostring(avm_memcell* param){assert(0); return "";}

unsigned char number_tobool (avm_memcell* m){return m->data.numVal != 0;}
unsigned char string_tobool (avm_memcell* m){ return m->data.strVal != NULL;}
unsigned char bool_tobool(avm_memcell* m){ return m->data.boolVal != 0;}
unsigned char table_tobool(avm_memcell* m){ return 1;}
unsigned char userfunc_tobool(avm_memcell* m){ return 1;}
unsigned char libfunc_tobool(avm_memcell* m){ return 1;}
unsigned char nil_tobool(avm_memcell* m){ return 0;}
unsigned char undef_tobool(avm_memcell* m){ assert(0); return 0;}

unsigned char avm_tobool (avm_memcell* m){
     assert(m->type >= 0 && m->type < undef_m);
     return (*toboolFuncs[m->type]) (m);
}

char* avm_tostring(avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return tostringFuncs[m->type](m);
}

unsigned char execute_relop(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)0);
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);	

	assert(rv1 && rv2);
	if (rv1->type == undef_m ||  rv1->type == libfunc_m  ){
		avm_error("Wrong type on Argument1!\n" , "");
		executionFinished = 1;
		return 0;
	}
	else if (rv2->type == undef_m ||  rv2->type == libfunc_m ){
		avm_error("Wrong type on Argument2!\n" , "");
		executionFinished = 1;
		return 0;
	}
	return cmpFuncs[instr->opcode - jeq_v] (rv1, rv2);	
}

unsigned char avm_eq(avm_memcell* arg1, avm_memcell* arg2) 	{ return arg1->data.numVal == arg2->data.numVal;}
unsigned char avm_neq(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal != arg2->data.numVal;}
unsigned char avm_lt(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal < arg2->data.numVal;}
unsigned char avm_gt(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal > arg2->data.numVal;}
unsigned char avm_gte(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal >= arg2->data.numVal;}
unsigned char avm_lte(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal <= arg2->data.numVal;}