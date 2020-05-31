#include "table.h"

char* typeStrings[] = {
     "number_m",
     "string_m",
     "bool_m",
     "table_m",
     "userfunc_m",
     "libfunc_m",
     "nil_m",
     "undef_m"
};

void execute_newtable(instruction* instr){
     avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)0);
     assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval));
     avm_memcellclear(lv);
     lv->type = table_m;
     lv->data.tableVal = avm_tablenew();
     avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablesetelem(instruction* instr){
     avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*)0);
     avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
     avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);
     assert(t && &stack[AVM_STACKSIZE] >= t && t > &stack[top]);
     assert(i && c);
     if(t->type != table_m){
          avm_error("illegal use of type %s as table!", typeStrings[t->type]);
     }else{
          avm_tablesetelem(t, i, c);
     }
}

void execute_tablegetelem(instruction* instr){
     avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
     avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*) 0);
     avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

     assert(lv && &stack[AVM_STACKSIZE] >= lv && lv > &stack[top] || lv==&retval);
     assert(t && &stack[AVM_STACKSIZE] >= t && t > &stack[top]);
     assert(i);

     avm_memcellclear(lv);
     lv->type = nil_m;

     if (t->type !=table_m){
          avm_error("illegal use of type %s as table!", typeStrings[t->type]);
     }
     else{
          avm_memcell* content = avm_tablegetelem(t, i);
          if(content) {
               avm_assign(lv , content);
          }
          else {
               char* ts = avm_tostring(t);
               char* is = avm_tostring(i);
               avm_warning("%s[%s] not found!");
               free(ts);
               free(is);
          }
     }
}
