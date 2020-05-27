#include "avm.h"

incomplete_jump*    ij_head   = (incomplete_jump*) 0;
unsigned            ij_total  = 0;
unsigned            currProcessedQuad;

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
	generate_NEWTABLE ,
	generate_JUMP ,
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

void instructions_backpatch (unsigned list, unsigned label) {
     printf("GAMISOU \n");
     while (list) {
          int next = quads[list].label;
          instructions[list].label = label;
          list = next;
     }
}


void make_operand(Expr* e, vmarg* arg){
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
               arg->id = strdup(e->sym->name);
               switch (e->sym->space) { 
 
                    case programvar     : arg->type = global_a; break;
                    case functionlocal  : arg->type = local_a; break;
                    case formalarg      : arg->type = formal_a; break;
                    default: assert(0);
               }
               break; /* from case newtable_e.*/
          }

          /* Constants */

          case constbool_e: {
               arg->id = strdup(e->sym->name);
               arg->val = e->boolConst;
               arg->type = bool_a; break;
          }
          case conststring_e: {
               arg->id = strdup(e->strConst);
               arg->val = consts_newstring(e->strConst);
               arg->type = string_a; break;
          }
          case constnum_e: {
               arg->id = strdup(e->sym->name);
               arg->val = consts_newnumber(e->numConst);
               arg->type = number_a; break;
          }

          case nil_e: arg->type = nil_a; break;

          /* Functions */
          case programfunc_e: {
               arg->id = strdup(e->sym->name);
               arg->val = userfuncs_newfunc(e->sym);
               arg->type = userfunc_a;
               break;
          }
          case libraryfunc_e: {
               arg->id = strdup(e->sym->name);
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
     t.label = currIns + 1;
     instructions[currIns++] = t;
     totalIns++;
}

void generate (vmopcode op, Quad* quad) {
     instruction t;
     t.opcode = op;
     t.arg1.type = 11;
     t.arg2.type = 11;
     t.result.type = 11;
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
void generate_ASSIGN (Quad* quad)        { generate(assign_v, quad);} 
void generate_NOP ()                    { instruction t; t.opcode=nop_v; instructions_emit(t); } 

unsigned currprocessedquad() {
     return currProcessedQuad;
}


void generate_relational (vmopcode  op, Quad* quad) {
     instruction t;
     t.opcode = op;
     if(quad->arg1) make_operand(quad->arg1, &t.arg1);  
     if(quad->arg2) make_operand(quad->arg2, &t.arg2);

     t.result.type = label_a;  
     if (quad->label != 0) {
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
     f = quad->arg1->sym;
     f->taddress = nextinstructionlabel();
     quad->taddress = nextinstructionlabel();
     
     userfuncs_newfunc(f);
     stack_push(stack, f);

     instruction t;
     t.opcode = funcenter_v;
     make_operand(quad->arg1 , &t.result);

     instructions_emit(t);
}

void generate_RETURN(Quad* quad){
     quad->taddress = nextinstructionlabel();
     Symbol* f;
     instruction t;
     t.opcode = assign_v;
     make_retvaloperand(&t.result);
     make_operand(quad->result, &t.arg1);
     instructions_emit(t);

     f = stack_top(stack);
     f->returnList = append(f->returnList, nextinstructionlabel());

     t.opcode = jump_v;
     
     reset_operand (&t.arg1);
     reset_operand (&t.arg2);
     t.result.type = label_a;
     instructions_emit(t);
}

void generate_FUNCEND(Quad* quad){
     Symbol* f;
     f = stack_pop(stack);
     if ( f->returnList) instructions_backpatch(f->returnList->retVal ,nextinstructionlabel());
     quad->taddress = nextinstructionlabel();
     instruction t;
     t.opcode = funcexit_v;
     make_operand(quad->arg1 , &t.result);
     instructions_emit(t);
}

void generate1(void) {
     unsigned i;
     initMem();
     for(i = 1; i < nextquad(); i++){
          currProcessedQuad = i;
         (*generators[quads[i].op])( (quads+i));
     }
     patch_incomplete_jumps();
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
     unsigned magic = 340200501;
     fp = fopen("mikriloulou.abc", "wb");
     fprintf(fp, "Magic: %d \n", magic);
     for ( int i = 0; i < nextinstructionlabel(); i++) {
          vmarg res = (instructions + i)->result;
          vmarg arg1 = (instructions + i)->arg1;
          vmarg arg2 = (instructions + i)-> arg2;
          printf("ASDA %d\n",i);
          //if((res.id && istempname(res.id)) ||
          //(arg1.id && istempname(arg1.id)) || (arg2.id && istempname(arg2.id))) continue;
          fprintf(fp, "%s ", opcodes[instructions[i].opcode]);
          printf("edw\n");
          switch ( res.type) {
               case label_a        : fprintf(fp, "00(label), %d ", res.val); break;
               case global_a       : fprintf(fp, "01(global), %d:%s ", res.val ,res.id); break;
               case formal_a       : fprintf(fp, "02(formal), %d:%s ", res.val ,res.id); break;
               case local_a        : fprintf(fp, "03(local), %d:%s ", res.val ,res.id); break;
               case bool_a         : fprintf(fp, "06(boolean), %d:%s ", res.val ,res.id); break;
               case retval_a       : fprintf(fp, "10(retval)"); break;
               case nil_a          : fprintf(fp, "07(NULL) "); break;
               case number_a       : fprintf(fp, "04(num), %d:%f ", res.val, numConsts[res.val]); break;
               case string_a       : fprintf(fp, "05(string), %d:\"%s\" ", res.val, stringConsts[res.val]); break;
               case userfunc_a     : fprintf(fp, "08(userfunc), %d:%s ", res.val, userFuncs[res.val].id); break;
               case libfunc_a      : fprintf(fp, "09(libfunc), %d:%s ", res.val,namedLibfuncs[res.val]); break;
               default             : break;
          }
          fprintf(fp, "\t");
          printf("edw1\n");
          switch ( arg1.type) {
               case label_a        : printf("edw2\n"); fprintf(fp, "00 (label), %d ", arg1.val); break;
               case global_a       : printf("edw2.1\n");fprintf(fp, "01(global), %d:%s ", arg1.val, arg1.id); break;
               case formal_a       : printf("edw2.2\n");fprintf(fp, "02(formal), %d:%s ", arg1.val ,arg1.id); break;
               case local_a        : printf("edw2.3\n"); /*fprintf(fp, "03(local), %d:%s ", arg1.val, arg1.id);*/ break;
               case bool_a         : printf("edw2.4\n"); fprintf(fp, "06(boolean), %d:%s ", arg1.val ,arg1.id); break;
               case retval_a       : printf("edw2.5\n"); fprintf(fp, "10(retval)"); break;
               case nil_a          : printf("edw2.6\n");fprintf(fp, "07(NULL) "); break;
               case number_a       : printf("edw2.7\n");fprintf(fp, "04(num), %d:%f ", arg1.val, numConsts[arg1.val]); break;
               case string_a       : printf("edw2.8\n");fprintf(fp, "05(string), %d:\"%s\" ", arg1.val,stringConsts[arg1.val]); break;
               case userfunc_a     : printf("edw2.9\n");fprintf(fp, "08(userfunc), %d:%s ", arg1.val, userFuncs[arg1.val].id); break;
               case libfunc_a      : printf("edw2.10\n");fprintf(fp, "09(libfunc), %d:%s ", arg1.val,namedLibfuncs[arg1.val]); break;
               default             : break;
          }
          fprintf(fp, "\t");
          
          switch ( arg2.type) {
               case label_a        : fprintf(fp, "00 (label), %d", arg2.val); break;
               case global_a       : fprintf(fp, "01(global), %d:%s ", arg2.val, arg2.id); break;
               case formal_a       : fprintf(fp, "02(formal), %d:%s ", arg2.val ,arg2.id); break;
               case local_a        : fprintf(fp, "03(local), %d:%s ", arg2.val, arg2.id); break;
               case bool_a         : fprintf(fp, "06(boolean), %d:%s ", arg2.val ,arg2.id); break;
               case retval_a       : fprintf(fp, "10(retval)"); break;
               case nil_a          : fprintf(fp, "(NULL) "); break;
               case number_a       : fprintf(fp, "04(num), %d:%f ", arg2.val, numConsts[arg2.val]); break;
               case string_a       : fprintf(fp, "05(string), %d:\"%s\" ", arg2.val,stringConsts[arg2.val]); break;
               case userfunc_a     : fprintf(fp, "08(userfunc), %d:%s ", arg2.val, userFuncs[arg1.val].id); break;
               case libfunc_a      : fprintf(fp, "09(libfunc), %d:%s ", arg2.val,namedLibfuncs[arg2.val]); break;
               default             : break;
          }
          printf("edw3\n");
          fprintf(fp, "\t");
          fprintf(fp, "\n");
     }
     
     fclose(fp);
}