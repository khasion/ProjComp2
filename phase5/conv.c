#include "conv.h"

tonumber_func_t tonumberFuncs[] = {
	number_tonumber,
	string_tonumber,
	bool_tonumber,
	table_tonumber,
	userfunc_tonumber,
	libfunc_tonumber,
	nil_tonumber,
	undef_tonumber,
};

tostring_func_t tostringFuncs[] = {
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

tobool_func_t toboolFuncs[] = {
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

double number_tonumber (avm_memcell* param) { return param->data.numVal;}
double string_tonumber (avm_memcell* param) { 
	int sum = 0;
	if ( !param->data.strVal) return 0;
	for (int i = 0; i < strlen(param->data.strVal); i++) {
		sum += param->data.strVal[i];
	}
	return sum;
}
double bool_tonumber (avm_memcell* param) { return param->data.boolVal;}
double table_tonumber (avm_memcell* param) { return param->data.tableVal->total; }
double userfunc_tonumber (avm_memcell* param) { return param->data.funcVal; }
double libfunc_tonumber (avm_memcell* param) { 
	int i;
	int sum = 0;
	for (i = 0; i < strlen(param->data.libfuncVal); i++) {
		sum += param->data.libfuncVal[i];
	}
	return sum;
}
double nil_tonumber (avm_memcell* param) { return 0;}
double undef_tonumber (avm_memcell* param) { return -1;}

char* number_tostring(avm_memcell* param){
	char* buff;
	buff = (char*) malloc(sizeof(char)*100);
	sprintf(buff,"%f",param->data.numVal);
	return buff;
}

char* string_tostring(avm_memcell* param) {
	return param->data.strVal;
}

char* bool_tostring(avm_memcell* param){
     if (param->data.boolVal) {
          return strdup("'true'");
     }
     return strdup("'false'");
}
char* table_tostring(avm_memcell* param){ 
	print_table(param);
     return "";
}
char* userfunc_tostring(avm_memcell* param){ 
     return userFuncs[param->data.funcVal].id;
}
char* libfunc_tostring(avm_memcell* param){ return param->data.libfuncVal;}
char* nil_tostring(avm_memcell* param) { return "0";}
char* undef_tostring(avm_memcell* param) {assert(0); return "";}

bool number_tobool (avm_memcell* m){return m->data.numVal != 0;}
bool string_tobool (avm_memcell* m){ return m->data.strVal != NULL;}
bool bool_tobool(avm_memcell* m){ return m->data.boolVal != 0;}
bool table_tobool(avm_memcell* m){ return 1;}
bool userfunc_tobool(avm_memcell* m){ return 1;}
bool libfunc_tobool(avm_memcell* m){ return 1;}
bool nil_tobool(avm_memcell* m){ return 0;}
bool undef_tobool(avm_memcell* m){ assert(0); return 0;}

double avm_tonumber (avm_memcell* m) {
     assert(m->type >= 0 && m->type < undef_m);
     return (*tonumberFuncs[m->type]) (m);
}

bool avm_tobool (avm_memcell* m){
     assert(m->type >= 0 && m->type < undef_m);
     return (*toboolFuncs[m->type]) (m);
}

char* avm_tostring(avm_memcell* m) {
	return tostringFuncs[m->type](m);
}