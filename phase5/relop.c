 #include "relop.h"

#define true 1
#define false 0

cmp_func_t cmpFuncs[] = {
	avm_eq,
	avm_neq,
	avm_lte,
	avm_gte,
	avm_lt,
	avm_gt
};

void execute_jump (instruction* instr) {
	pc = instr->result.val;
}

void execute_relop(instruction* instr){
	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);
	
	bool result = 0;
	assert(rv1 && rv2);

	if (rv1->type == undef_m ||  rv2->type == undef_m  ){
		avm_error("'undef' involved in comparisson.\n" , "");
		return ;
	}
	else if (rv1->type == nil_m ||  rv2->type == nil_m ){
		avm_error("'nil' involved in comparisson.\n" , "");
		return ;
	}
	switch ( rv1->type) {
		case number_m 		:rv2->data.numVal = avm_tonumber(rv2); break;
		case string_m  	:	rv2->data.strVal = strdup(avm_tostring(rv2)); break;
		case bool_m		:	rv2->data.boolVal = avm_tobool(rv2); break;
		default			: break;
	}
	
	result = cmpFuncs[instr->opcode - jeq_v] (rv1, rv2);
	if ( result ) {
		pc = instr->result.val;
	}
}

bool avm_eq(avm_memcell* arg1, avm_memcell* arg2) 	{
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal == arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) == 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal == arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0; 
}
bool avm_neq(avm_memcell* arg1, avm_memcell* arg2)	{ 
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal != arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) != 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal != arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0;
}
bool avm_lt(avm_memcell* arg1, avm_memcell* arg2)		{ 
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal < arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) < 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal < arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0;
}

bool avm_gt(avm_memcell* arg1, avm_memcell* arg2)		{ 
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal > arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) > 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal > arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0;
}
bool avm_gte(avm_memcell* arg1, avm_memcell* arg2)	{ 
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal >= arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) >= 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal >= arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0;
}

bool avm_lte(avm_memcell* arg1, avm_memcell* arg2)	{
	switch ( arg1->type) {
		case number_m 	: {
			arg2->data.numVal = avm_tonumber(arg2);
			return arg1->data.numVal <= arg2->data.numVal; break;
		}
		case string_m  	:{
			arg2->data.strVal = strdup(avm_tostring(arg2)); 
			return strcmp(arg1->data.strVal, arg2->data.strVal) <= 0; break;
		}
		case bool_m		:{
			arg2->data.boolVal = avm_tobool(arg2); 
			return arg1->data.boolVal <= arg2->data.boolVal; break;
		}
		case table_m :{
			return arg1->data.tableVal == arg2->data.tableVal;
		}
		default	: break;
	}
	return 0;
}