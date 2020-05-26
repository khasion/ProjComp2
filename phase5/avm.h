#ifndef AVM_H
#define AVM_H

#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;

typedef void (*execute_func_t)(instruction*);
struct avm_table;

enum avm_memcell_t{
  number_m	= 0,
	string_m	= 1,
	bool_m		= 2,
	table_m		= 3,
	userfunc_m	= 4,
	libfunc_m	= 5,
	nil_m		= 6,
	undef_m		= 7
};

struct avm_memcell{
  avm_memcell_t type;
  union{
    double numVal;
    char* strVal;
    unsigned boolVal;
    avm_table* tableVal;
    unsigned funcVal;
    char* libfuncVal;
  }data;
};

double const_getnumber(unsigned index);
char* consts_getstring(unsigned index);
char* libfuncs_getused(unsigned index);
extern void avm_warning(char* war);
extern void avm_error(char* err);
extern char* avm_tostring(avm_memcell*);
extern void avm_calllibfunc(char* funcName);
extern void avm_callsaveenviroment(void);
extern userfunc* avm_getfuncinfo(unsigned address);
typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc(char* id);
extern void avm_assign(avm_memcell* lv, avm_memcell* rv);
avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index, avm_memcell* content);
void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content);

#endif