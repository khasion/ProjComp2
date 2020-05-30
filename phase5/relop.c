#include "relop.h"

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

char* number_tostring(avm_memcell* param){return param->data.strVal;}
char* strng_tostring(avm_memcell* param) { return param->data.strVal;}
char* bool_tostring(avm_memcell* param){ return param->data.strVal;}
char* table_tostring(avm_memcell* param){ return "1";}
char* userfunc_tostring(avm_memcell* param){ return "1";}
char* libfunc_tostring(avm_memcell* param){ return "1";}
char* nil_tostring(avm_memcell* param) { return "0";}
char* undef_tostring(avm_memcell* param){assert(0); return "";}

unsigned char number_tobool (avm_memcell* m){ return m->data.numVal != 0;}
unsigned char string_tobool (avm_memcell* m){ return m->data.strVal != 0;}
unsigned char bool_tobool(avm_memcell* m){ return m->data.boolVal != 0;}
unsigned char table_tobool(avm_memcell* m){ return 1;}
unsigned char userfunc_tobool(avm_memcell* m){ return 1;}
unsigned char libfunc_tobool(avm_memcell* m){ return 1;}
unsigned char nil_tobool(avm_memcell* m){ return 0;}
unsigned char undef_tobool(avm_memcell* m){ assert(0); return 0;}

