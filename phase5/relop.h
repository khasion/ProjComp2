typedef char* (*tostring_func_t)(avm_memcell*);

void execute_jeq(instruction* instr);
void execute_jne(instruction* instr);
void execute_jle(instruction* instr);
void execute_jge(instruction* instr);
void execute_jlt(instruction* instr);
void execute_jgt(instruction* instr);

char* number_tostring(avm_memcell* param);
char* strng_tostring(avm_memcell* param);
char* bool_tostring(avm_memcell* param);
char* table_tostring(avm_memcell* param);
char* userfunc_tostring(avm_memcell* param);
char* libfunc_tostring(avm_memcell* param);
char* nil_tostring(avm_memcell* param);
char* undef_tostring(avm_memcell* param);

unsigned char number_tobool (avm_memcell* m);
unsigned char string_tobool (avm_memcell* m);
unsigned char bool_tobool (avm_memcell* m);
unsigned char table_tobool (avm_memcell* m);
unsigned char userfunc_tobool (avm_memcell* m);
unsigned char libfunc_tobool (avm_memcell* m);
unsigned char nil_tobool (avm_memcell* m);
unsigned char undef_tobool (avm_memcell* m);
unsigned char avm_tobool(avm_memcell* m);

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

char* avm_tostring(avm_memcell* m);
unsigned char avm_tobool(avm_memcell* m);

