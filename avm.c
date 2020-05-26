#include "avm.h"

incomplete_jump*    ij_head   = (incomplete_jump*) 0;
unsigned            ij_total  = 0;

instruction* instructions = (instruction*) 0;
unsigned currIns = 0;
unsigned totalIns = 0;


generator_func_t (generators[]) = {
	generate_ASSIGN ,
	generate_ADD ,
     generate_SUB ,
     generate_MUL ,
     generate_DIV ,
     generate_MOD ,
	generate_UMINUS ,
	generate_AND,
	generate_OR ,
	generate_NOT ,
	generate_IF_EQ ,
	generate_IF_NOTEQ ,	
	generate_IF_LESSEQ ,
	generate_IF_GREATEREQ ,
	generate_IF_LESS ,
	generate_IF_GREATER ,
	generate_CALL ,
	generate_PARAM ,
	generate_RETURN ,
	generate_GETRETVAL ,
	generate_FUNCSTART ,
	generate_FUNCEND ,
	generate_JUMP ,
	generate_NEWTABLE ,
     generate_TABLEGETELEM ,
     generate_TABLESETELEM ,
     generate_NOP
};

/*avmbinaryfile(){
    return magicnumber() and aarrays() and code();
}

magicnumber(){
    return match(unsigned) and currtoken.intval == magicnumber;
}

arrays(){
    return strings() and userfunctions() and libfunctions();
}

strings(){
    unsigned n;
    if (!match(unsigned)) return false;
    else{
        for (n=currtoken.intval; n; --n){
            string();
    }
    */

void ins_init() {
     instructions = (instruction*) malloc(sizeof(instruction)*EXPAND_SIZE);
     currIns = 0;
     totalIns = EXPAND_SIZE;
}

void expand_ins() {
     assert(totalIns <= currIns);
     instruction* t = (instruction*) malloc(sizeof(instruction)*EXPAND_SIZE+totalIns*sizeof(instruction));
     if (instructions) {
          memcpy(t, quads, totalIns*sizeof(instruction));
          free(instructions);
     }
     instructions = t;
     totalIns += EXPAND_SIZE;
}

void make_operand(Expr* e, vmarg* arg){
     
     printf("type: %d\n", e->type);
     switch(e->type) {
          
          /* All those below use a variable for storage.
          */
          case var_e:
          case tableitem_e:
          case arithexpr_e:
          case boolexpr_e:
          case assignexpr_e:
          case newtable_e: {

               assert(e->sym);
               arg->val = e->sym->offset;

               switch (e->sym->space) { 
                    case programvar:    arg->type = global_a; break;
                    case functionlocal: arg->type = local_a; break;
                    case formalarg:     arg->type = formal_a; break;
                    default: assert(0);
               }
               table_insert(e);
               break; /* from case newtable_e.*/
          }

          /* Constants */

          case constbool_e: {
               arg->val = e->boolConst;
               arg->type = bool_a; break;
          }
          case conststring_e: {
               arg->val = consts_newstring(e->strConst);
               arg->type = string_a; break;
          }
          case constnum_e: {
               arg->val = consts_newnumber(e->numConst);
               printf("ASD\n");
               arg->type = number_a; break;
          }

          case nil_e: arg->type = nil_a; break;

          /* Functions */
          case programfunc_e: {
               arg->val = userfuncs_newfunc(e->sym);
               break;
          }
          case libraryfunc_e: {
               arg->type = libfunc_a;
               arg->val = libfuncs_newused(e->sym->name);
               break;
          }
          default: assert(0);
     }
}

void make_numberoperand (vmarg* arg, double val){
     arg->val = consts_newnumber(val);
     arg->type = number_a;
}

void make_booloperand (vmarg* arg , bool val){
     arg->val = val;
     arg->type = bool_a;
}

void make_retvaloperand (vmarg* arg){
     arg->type = retval_a;
}

/* Otan kanoume reset_operand toy kanoyme type nil_a ? h apla NULL ?
*/
void reset_operand(vmarg* arg) {
     arg = NULL;
}

void patch_incomplete_jumps() {  
     incomplete_jump* temp;
     temp = ij_head;
     while (temp) {
          if (temp->iaddress == nextquad()){
               instructions[temp->instrNo].result.val = nextinstructionlabel();
          }   
          else {
               instructions[temp->instrNo].result.val = quads[temp->iaddress].taddress;  
          }
     }
}

void add_incomplete_jump(unsigned n, unsigned label) {
    incomplete_jump* newjump;
    newjump = (incomplete_jump*) malloc(sizeof(incomplete_jump));

    newjump->instrNo = n;
    newjump->iaddress = label;
    

    newjump->next = ij_head;
    ij_head = newjump;
}

unsigned nextinstructionlabel() {
     return currIns;
}

void instructions_emit(instruction t) {
     if (currIns >= totalIns) expand_ins();
     instructions[currIns++] = t;
     totalIns++;
}

void generate (vmopcode op, Quad* quad) {
     instruction t;
     t.opcode = op;
     if ( quad->arg1) make_operand(quad->arg1, &t.arg1);  
     if ( quad->arg2 ) make_operand(quad->arg2, &t.arg2);
     if ( quad->result ) make_operand(quad->result, &t.result);
     quad->taddress = nextinstructionlabel();
     instructions_emit(t);
}  

void generate_ADD (Quad* quad)  { generate(add_v, quad); } 
void generate_SUB (Quad* quad)  { generate(sub_v, quad); } 
void generate_MUL (Quad* quad)  { generate(mul_v, quad); } 
void generate_DIV (Quad* quad)  { generate(div_v, quad); } 
void generate_MOD (Quad* quad)  { generate(mod_v, quad); }

void generate_UMINUS (Quad* quad) {
     instruction t;
     t.opcode = mul_v;
     make_operand(quad->arg1, &t.arg1);
     make_numberoperand(&t.arg2, -1);
     make_operand(quad->result, &t.result);
     instructions_emit(t);
}

void generate_NEWTABLE (Quad* quad)      { generate(newtable_v, quad); } 
void generate_TABLEGETELEM (Quad* quad)  { generate(tablegetelem_v, quad); } 
void generate_TABLESETELEM (Quad* quad)  { generate(tablesetelem_v, quad); } 
void generate_ASSIGN (Quad* quad)        { generate(assign_v, quad); } 
void generate_NOP ()                    { instruction t; t.opcode=nop_v; instructions_emit(t); } 

unsigned currprocessedquad() {
     return nextquad() - 1;
}

/* Den katalavainw to currprocessedquad() .. mhpws einai nextquad()-1 ?
*/
void generate_relational (vmopcode  op, Quad* quad) {
     instruction t;
     t.opcode = op;
     make_operand(quad->arg1, &t.arg1);  
     make_operand(quad->arg2, &t.arg2);    

     t.result.type = label_a;  
     if (quad->label < currprocessedquad()) {
          t.result.val = quads[quad->label].taddress;  
     }
     else {
          add_incomplete_jump(nextinstructionlabel(), quad->label); 
     }
     quad->taddress = nextinstructionlabel();  
     instructions_emit(t); 
}

void generate_JUMP (Quad* quad)  { generate_relational(jump_v, quad); } 
void generate_IF_EQ (Quad* quad)   { generate_relational(jeq_v, quad); } 
void generate_IF_NOTEQ(Quad* quad)  { generate_relational(jne_v, quad); } 
void generate_IF_GREATER (Quad* quad)  { generate_relational(jqt_v, quad); } 
void generate_IF_GREATEREQ(Quad* quad)  { generate_relational(jge_v, quad); }
void generate_IF_LESS (Quad* quad)   { generate_relational(jlt_v, quad); } 
void generate_IF_LESSEQ (Quad* quad)  { generate_relational(jle_v, quad); }

void generate_NOT (Quad* quad) {    

     quad->taddress = nextinstructionlabel();  
     instruction t;

     t.opcode = jeq_v;  
     make_operand(quad->arg1, &t.arg1);  
     make_booloperand(&t.arg2, false);  
     t.result.type = label_a;  
     t.result.val  = nextinstructionlabel() + 3;  
     instructions_emit(t);

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, false);  
     reset_operand(&t.arg2);  
     make_operand(quad->result, &t.result);  
     instructions_emit(t);

     t.opcode = jump_v;  
     reset_operand (&t.arg1);  
     reset_operand(&t.arg2);
     t.result.type = label_a;  
     t.result.val  = nextinstructionlabel() +2;  
     instructions_emit(t);    

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, true);  
     reset_operand(&t.arg2);  
     make_operand(quad->result, &t.result);  
     instructions_emit(t); 
} 

void generate_OR (Quad* quad) {

     quad->taddress = nextinstructionlabel();  
     instruction t;    

     t.opcode = jeq_v;
     make_operand(quad->arg1, &t.arg1);  
     make_booloperand(&t.arg2, true);  
     t.result.type = label_a;  
     t.result.val  = nextinstructionlabel() + 4;  
     instructions_emit(t);

     make_operand(quad->arg2, &t.arg1);  
     t.result.val  = nextinstructionlabel() + 3;  
     instructions_emit(t);

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, false);  
     reset_operand(&t.arg2);
     make_operand(quad->result, &t.result);  
     instructions_emit(t);    

     t.opcode = jump_v;  
     reset_operand (&t.arg1);  
     reset_operand(&t.arg2);  
     t.result.type = label_a;
     t.result.val  = nextinstructionlabel() + 2;  
     instructions_emit(t);    

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, true);  
     reset_operand(&t.arg2);  
     make_operand(quad->result, &t.result);  
     instructions_emit(t); 
}

void generate_AND (Quad* quad) {

     quad->taddress = nextinstructionlabel();  
     instruction t;    

     t.opcode = jeq_v;
     make_operand(quad->arg1, &t.arg1);  
     make_booloperand(&t.arg2, true);  
     t.result.type = label_a;  
     t.result.val  = nextinstructionlabel() + 1;  
     instructions_emit(t);

     make_operand(quad->arg2, &t.arg1);
     t.result.val  = nextinstructionlabel() + 1;  
     instructions_emit(t);

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, false);  
     reset_operand(&t.arg2);
     make_operand(quad->result, &t.result);  
     instructions_emit(t);    

     t.opcode = jump_v;  
     reset_operand (&t.arg1);  
     reset_operand(&t.arg2);  
     t.result.type = label_a;  
     t.result.val  = nextinstructionlabel() + 2;  
     instructions_emit(t);    

     t.opcode = assign_v;  
     make_booloperand(&t.arg1, true);  
     reset_operand(&t.arg2);  
     make_operand(quad->result, &t.result);  
     instructions_emit(t); 
}

void generate_PARAM(Quad* quad) {  
     quad->taddress = nextinstructionlabel();
     instruction t;  
     t.opcode = pusharg_v;
     make_operand(quad->arg1, &t.arg1);  
     instructions_emit(t); 
}   

void generate_CALL(Quad* quad) {  
     quad->taddress = nextinstructionlabel();  
     instruction t;  
     t.opcode = call_v;  
     make_operand(quad->arg1, &t.arg1);  
     instructions_emit(t); 
}   
void generate_GETRETVAL(Quad* quad) {
     quad->taddress = nextinstructionlabel();
     instruction t;  
     t.opcode = assign_v;  
     make_operand(quad->result, &t.result);  
     make_retvaloperand(&t.arg1);  
     instructions_emit(t);
}

void generate_FUNCSTART(Quad* quad){
     Symbol* f;
     f = quad->result->sym;
     f->taddress = nextinstructionlabel();
     quad->taddress = nextinstructionlabel();

     userfuncs_newfunc(f);
     stack_push(stack, f);

     instruction t;
     t.opcode = funcenter_v;
     make_operand(quad->result , &t.result);
     instructions_emit(t);
}

void generate_RETURN(Quad* quad){
     quad->taddress = nextinstructionlabel();
     Symbol* f;

     instruction t;
     t.opcode = assign_v;
     make_retvaloperand(&t.result);
     make_operand(quad->arg1, &t.arg1);
     instructions_emit(t);

     f = stack_top(stack);
     append(f->returnList , nextinstructionlabel());

     t.opcode = jump_v;
     reset_operand (&t.arg1);
     reset_operand (&t.arg2);
     t.result.type = label_a;
     instructions_emit(t);
}

void generate_FUNCEND(Quad* quad){
     Symbol* f;
     f = stack_pop(stack);
     backpatch(f->returnList->retVal ,nextinstructionlabel());
     quad->taddress = nextinstructionlabel();
     instruction t;
     t.opcode = funcexit_v;
     make_operand(quad->result , &t.result);
     instructions_emit(t);
}

void generate1(void) {
     unsigned i;
     initMem();
     for(i = 1; i < nextquad(); i++){
          printf("HELASD\n");
         (*generators[quads[i].op])( (quads+i));
     }
}

void print_instructions() {
     char* opcodes[25] = {
     "assign_v",           "add_v",              "sub_v",
     "mul_v",              "div_v",              "mod_v",
     "uminus_v",           "and_v",              "or_v",
     "not_v",              "jeq_v",              "jne_v",
     "jle_v",              "jge_v",              "jlt_v",
     "jqt_v",              "call_v",             "pusharg_v",
     "funcenter_v",        "funcexit_v",         "newtable_v",
     "tablegetelem_v",     "tablesetelem_v",     "jump_v",
     "nop_v"
     };
     FILE* fp;
     unsigned magic = 340;
     fp = fopen("mikriloulou.abc", "wb");
     fprintf(fp, "%d \n", magic);
     for ( int i = 0; i < nextinstructionlabel(); i++) {
          fprintf(fp, "%s ", opcodes[instructions[i].opcode]);
          vmarg res = (instructions + i)->result;
          switch ( res.type) {
               case label_a        :
               case global_a       :
               case formal_a       :
               case local_a        :
               case bool_a         : fprintf(fp, "%f ", numConsts[res.val]);
               case retval_a       :
               case nil_a          : fprintf(fp, "(NULL) ");
               case number_a       : fprintf(fp, "%f ", numConsts[res.val]);
               case string_a       : fprintf(fp, "%s ", stringConsts[res.val]);
               case userfunc_a     : fprintf(fp, "%s ", userFuncs[res.val].id);
               case libfunc_a      : fprintf(fp, "%s ", namedLibfuncs[res.val]);
               default             : break;
          }
          vmarg arg1 = (instructions + i)->arg1;
          switch ( arg1.type) {
               case label_a        :
               case global_a       :
               case formal_a       :
               case local_a        :
               case bool_a         :
               case retval_a       :
               case nil_a          :
               case number_a       : fprintf(fp, "%f ", numConsts[arg1.val]);
               case string_a       : fprintf(fp, "%s ", stringConsts[arg1.val]);
               case userfunc_a     : fprintf(fp, "%s ", userFuncs[arg1.val].id);
               case libfunc_a      : fprintf(fp, "%s ", namedLibfuncs[arg1.val]);
               default             : break;
          }
          vmarg arg2 = (instructions + i)-> arg2;
          switch ( arg2.type) {
               case label_a        :
               case global_a       :
               case formal_a       :
               case local_a        :
               case bool_a         :
               case retval_a       :
               case nil_a          :
               case number_a       : fprintf(fp, "%f ", numConsts[arg2.val]);
               case string_a       : fprintf(fp, "%s ", stringConsts[arg2.val]);
               case userfunc_a     : fprintf(fp, "%s ", userFuncs[arg2.val].id);
               case libfunc_a      : fprintf(fp, "%s ", namedLibfuncs[arg2.val]);
               default             : break;
          }
          fprintf(fp, "\n");
     }
     fclose(fp);
}