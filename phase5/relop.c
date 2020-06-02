 #include "relop.h"

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
	if ( rv1->type != rv2->type) {
		avm_error("type error", "");
		return;
	}
	rv1->data.numVal = avm_tonumber(rv1);
	rv2->data.numVal = avm_tonumber(rv2);
	result = cmpFuncs[instr->opcode - jeq_v] (rv1, rv2);
	//printf("GAMIEME OXI \n");
	if ( result ) {
		pc = instr->result.val;
	}
}

bool avm_eq(avm_memcell* arg1, avm_memcell* arg2) 	{ return arg1->data.numVal == arg2->data.numVal;}
bool avm_neq(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal != arg2->data.numVal;}
bool avm_lt(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal < arg2->data.numVal;}
bool avm_gt(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal > arg2->data.numVal;}
bool avm_gte(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal >= arg2->data.numVal;}
bool avm_lte(avm_memcell* arg1, avm_memcell* arg2)	{ return arg1->data.numVal <= arg2->data.numVal;}