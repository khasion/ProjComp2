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

addTable_func_t addTableFuncs[] = {
     add_indexedNum,
     add_indexedString,
     add_indexedBool,
     add_indexedTable,
     add_indexedFunc,
     add_indexedlibFunc
};

void execute_newtable(instruction* instr){
     avm_memcell* lv = avm_translate_operand(&instr->arg1, (avm_memcell*)0);
     //assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval));
     avm_memcellclear(lv);
     
     lv->type = table_m;
     lv->data.tableVal = avm_tablenew();
     avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablesetelem(instruction* instr) {
     avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*)0);
     avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
     avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);
     
     //assert(t && &stack[AVM_STACKSIZE] >= t && t > &stack[top]);
     assert(i && c);
     if(t->type != table_m) {
          avm_error("illegal use of type %s as table!", typeStrings[t->type]);
     }else{
          avm_tablesetelem(t, i, c);
     }
}

void execute_tablegetelem(instruction* instr){
     avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
     avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*) 0);
     avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

     //assert(lv && &stack[AVM_STACKSIZE] >= lv && lv > &stack[top] || lv==&retval);
     //assert(t && &stack[AVM_STACKSIZE] >= t && t > &stack[top]);
     assert(i);

     avm_memcellclear(lv);
     lv->type = nil_m;

     if (t->type !=table_m){
          avm_error("illegal use of type %s as table!", typeStrings[t->type]);
     }
     else {
          avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
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

avm_memcell* avm_tablegetelem (avm_table* t, avm_memcell* index) {
     avm_table_bucket* temp;
     int result = 0;
     for (int i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          temp = t->numIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : if (temp->key.type == number_m) result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     for (int i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          temp = t->strIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     for (int i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          temp = t->boolIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default        : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     for (int i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          temp = t->userFuncIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     for (int i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          temp = t->libFuncIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default        : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     for (int i = 0; AVM_TABLE_HASHSIZE; i++) {
          temp = t->tableIndexed[i];
          while (temp) {
               switch (index->type) {
                    case number_m : result = temp->key.data.numVal == index->data.numVal; break;
                    case string_m : if (temp->key.type == string_m ) result = strcmp(temp->key.data.strVal, index->data.strVal) == 0; break;
                    default       : result = 0;
               }
               if (result) {
                    return &temp->value;
               }
               temp = temp->next;
          }
     }
     return NULL;
}

void avm_tablesetelem (avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     t->data.tableVal = addTableFuncs[content->type](t, index, content);
     t->data.tableVal->total++;
}

void avm_tableincrefcounter (avm_table* t) {
     ++t->refCounter;
}

void avm_tabledecrefcounter (avm_table* t) {
     assert(t->refCounter > 0);
     if (!--t->refCounter) {
          avm_tabledestroy(t);
     }
}

void avm_tablebucketsinit (avm_table_bucket** p) {
     p = (avm_table_bucket**) malloc(sizeof(avm_table_bucket)*AVM_TABLE_HASHSIZE);
}

avm_table* add_indexedNum(avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     avm_table_bucket* b;
     avm_table_bucket* temp;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;

     //hash = t->data.tableVal->total%AVM_TABLE_HASHSIZE;
     switch (index->type) {
          case number_m: hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default       : assert(0);
     }
     
     b->next = t->data.tableVal->numIndexed[hash];
     t->data.tableVal->numIndexed[hash] = b;
     return t->data.tableVal;
}
avm_table* add_indexedString(avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     avm_table_bucket* b;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;
     
     switch (index->type) {
          case number_m: hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default       : assert(0);
     }

     b->next = t->data.tableVal->strIndexed[hash];
     t->data.tableVal->strIndexed[hash] = b;
     return t->data.tableVal;
     
}
avm_table* add_indexedBool(avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     avm_table_bucket* b;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;

     switch (index->type) {
          case number_m: hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default       : assert(0);
     }

     b->next = t->data.tableVal->boolIndexed[hash];
     t->data.tableVal->boolIndexed[hash] = b;
     return t->data.tableVal;
}
avm_table* add_indexedFunc(avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     avm_table_bucket* b;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;

     switch (index->type) {
          case number_m: hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default       : assert(0);
     }
     b->next = t->data.tableVal->userFuncIndexed[hash];
     t->data.tableVal->userFuncIndexed[hash] = b;
     return t->data.tableVal;
}
avm_table* add_indexedlibFunc(avm_memcell* t, avm_memcell* index, avm_memcell* content){
     avm_table_bucket* b;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;

     switch (index->type) {
          case number_m       : hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m       : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default             : assert(0);
     }
     b->next = t->data.tableVal->libFuncIndexed[hash];
     t->data.tableVal->libFuncIndexed[hash] = b;
     return t->data.tableVal;
}

avm_table* add_indexedTable (avm_memcell* t, avm_memcell* index, avm_memcell* content) {
     avm_table_bucket* b;
     int hash;
     b = (avm_table_bucket*) malloc(sizeof(avm_table_bucket));
     b->key = *index;
     b->value = *content;
     b->next = NULL;

     switch (index->type) {
          case number_m       : hash = (int)index->data.numVal%AVM_TABLE_HASHSIZE; break;
          case string_m       : hash = (int)string_tonumber(index)%AVM_TABLE_HASHSIZE; break;
          default             : assert(0);
     }
     b->next = t->data.tableVal->tableIndexed[hash];
     t->data.tableVal->tableIndexed[hash] = b;
     return t->data.tableVal;
}

void print_table (avm_memcell* t) {
     int i;
     if (t->data.tableVal->explored) return;
     printf("[");
     t->data.tableVal->explored = 1;
     for ( i = 0; i < AVM_TABLE_HASHSIZE; i++) {
          if (t->data.tableVal->numIndexed[i]) {
               printf("%s,", avm_tostring(&t->data.tableVal->numIndexed[i]->value));
          }
          if (t->data.tableVal->strIndexed[i]) {
               printf("%s,", avm_tostring(&t->data.tableVal->strIndexed[i]->value));
          }
          if (t->data.tableVal->boolIndexed[i]) {
               printf("%s,", avm_tostring(&t->data.tableVal->boolIndexed[i]->value));
          }
          if (t->data.tableVal->userFuncIndexed[i]) {
               printf("%s,", avm_tostring(&t->data.tableVal->userFuncIndexed[i]->value));
          }
          if (t->data.tableVal->libFuncIndexed[i]) {
               printf("%s,", avm_tostring(&t->data.tableVal->libFuncIndexed[i]->value));
          }
          /*if (t->data.tableVal->tableIndexed[i]) {
               print_table(&t->data.tableVal->tableIndexed[i]->value); 
          }*/
     }
     printf("]");
}

avm_table* avm_tablenew (void) {
     avm_table* t = (avm_table* ) malloc(sizeof(avm_table));
     AVM_WIPEOUT(*t);
     t->refCounter = t->total = 0;
     t->explored = 0;
     avm_tablebucketsinit(t->numIndexed);
     avm_tablebucketsinit(t->strIndexed);
     avm_tablebucketsinit(t->boolIndexed);
     avm_tablebucketsinit(t->tableIndexed);
     avm_tablebucketsinit(t->userFuncIndexed);
     avm_tablebucketsinit(t->libFuncIndexed);

     return t;
}

void memclear_table (avm_memcell* m){
     assert (m->data.tableVal);
     avm_tabledecrefcounter(m->data.tableVal);
}

void avm_tablebucketsdestroy (avm_table_bucket** p) {
     for (int i=0; i<AVM_TABLE_HASHSIZE; ++i, ++p) {
          for (avm_table_bucket* b = *p; b;) {
               avm_table_bucket* del = b;
               b = b->next;
               avm_memcellclear(&del->key);
               avm_memcellclear(&del->value);
               free(del);
          }
          //p[i] = (avm_table_bucket*) 0;
     }
}

void avm_tabledestroy (avm_table* t) {
     avm_tablebucketsdestroy(t->strIndexed);
     avm_tablebucketsdestroy(t->numIndexed);
     avm_tablebucketsdestroy(t->boolIndexed);
     //avm_tablebucketsdestroy(t->tableIndexed);
     avm_tablebucketsdestroy(t->userFuncIndexed);
     avm_tablebucketsdestroy(t->libFuncIndexed);
     free(t);
}
