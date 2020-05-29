#include "avm.h"

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
};

void ins_init() {
     instructions = (instruction*) malloc(sizeof(instruction)*EXPAND_SIZE);
     for (int i = 0; i < EXPAND_SIZE; i++) {
          instructions[i].opcode = nop_v; 
          reset_operand(&instructions[i].result);
          reset_operand(&instructions[i].arg2);
          reset_operand(&instructions[i].arg1);
     }
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

void instructions_backpatch (retList* list, unsigned label) {
    retList* temp;
    temp = list;
    while (temp) {
         if (instructions[temp->retVal].result.type == label_a) {
              instructions[temp->retVal].result.val = label;
         }
         temp = temp->next;
    }
}

void patch_all () {
     for (int i = 1; i < nextquad(); i++) {
          if (instructions[quads[i].taddress].result.type == label_a) {
               instructions[quads[i].taddress].result.val = quads[quads[i].label].taddress;
          }
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

          case constbool_e:
               arg->id = strdup(e->sym->name);
               arg->val = e->boolConst;
               arg->type = bool_a; break;
          case conststring_e:
               arg->id = strdup(e->strConst);
               arg->val = consts_newstring(e->strConst);
               arg->type = string_a; break;
          case constnum_e:
               arg->id = strdup(e->sym->name);
               arg->val = consts_newnumber(e->numConst);
               arg->type = number_a; break;
          case nil_e: arg->type = nil_a; break;

          /* Functions */
          case programfunc_e:
               arg->id = strdup(e->sym->name);
               arg->val = e->sym->taddress;
               arg->type = userfunc_a;
               break;
          case libraryfunc_e:
               arg->id = strdup(e->sym->name);
               arg->type = libfunc_a;
               arg->val = libfuncs_newused(e->sym->name);
               break;
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
     arg->type = nil_a;
}


unsigned nextinstructionlabel() {
     return currIns;
}

void instructions_emit(instruction t) {
     if (currIns >= totalIns) expand_ins();
     instruction* temp = instructions + currIns++;
     temp->opcode = t.opcode;
     temp->arg1 = t.arg1;
     temp->arg2 = t.arg2;
     temp->result = t.result;
     temp->label = t.label;
     temp->srcLine = t.srcLine;
}

void generate (vmopcode op, Quad* quad) {
     instruction t;
     t.opcode = op;
     reset_operand(&t.arg1);
     reset_operand(&t.arg2);
     reset_operand(&t.result);
     if ( quad->arg1) {
          make_operand(quad->arg1, &t.arg1);  
     }
     if ( quad->arg2 ) {
          make_operand(quad->arg2, &t.arg2);
     }
     if ( quad->result ) {
          make_operand(quad->result, &t.result);
     }
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
void generate_NOP ()                     { instruction t; t.opcode=nop_v; instructions_emit(t); } 

unsigned currprocessedquad() {
     return currProcessedQuad;
}

void generate_relational (vmopcode  op, Quad* quad) {
     instruction t;
     reset_operand(&t.arg1);
     reset_operand(&t.arg2);
     reset_operand(&t.result);
     t.opcode = op;
     if(quad->arg1) {
          make_operand(quad->arg1, &t.arg1);  
     }
     if(quad->arg2) {
          make_operand(quad->arg2, &t.arg2);
     }
     
     t.result.type = label_a;
     quad->taddress = nextinstructionlabel();
     instructions_emit(t);
}

void generate_JUMP (Quad* quad)         { generate_relational(jump_v, quad); } 
void generate_IF_EQ (Quad* quad)        { generate_relational(jeq_v, quad); } 
void generate_IF_NOTEQ(Quad* quad)      { generate_relational(jne_v, quad); } 
void generate_IF_GREATER (Quad* quad)   { generate_relational(jqt_v, quad); } 
void generate_IF_GREATEREQ(Quad* quad)  { generate_relational(jge_v, quad); }
void generate_IF_LESS (Quad* quad)      { generate_relational(jlt_v, quad); } 
void generate_IF_LESSEQ (Quad* quad)    { generate_relational(jle_v, quad); }

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

     reset_operand(&t.arg1);
     reset_operand(&t.arg2);
     instructions_emit(t);
}

void generate_RETURN(Quad* quad){
     quad->taddress = nextinstructionlabel();
     Symbol* f;
     instruction t;
     reset_operand(&t.arg1);
     reset_operand(&t.arg2);
     reset_operand(&t.result);
     t.opcode = assign_v;
     make_retvaloperand(&t.result);
     make_operand(quad->arg1, &t.arg1);
     instructions_emit(t);

     f = stack_top(stack);
     f->returnList = append(f->returnList, nextinstructionlabel());

     t.opcode = jump_v;
     reset_operand (&t.arg1);
     reset_operand (&t.arg2);
     t.result.type = label_a;
     //instructions_emit(t);
}

void generate_FUNCEND(Quad* quad){
     instruction t;
     reset_operand(&t.arg1);
     reset_operand(&t.arg2);
     stack_pop(stack);
     quad->taddress = nextinstructionlabel();
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
     patch_all();
}

void print_instructions(FILE* fp, vmarg arg) {
          char* str;
          str = (char*) malloc(sizeof(char)*30);
          switch ( arg.type) {
               case label_a        : sprintf(str, "|00(label) %d", arg.val); break;
               case global_a       : sprintf(str, "|01(global) %d:%s", arg.val ,arg.id); break;
               case formal_a       : sprintf(str, "|02(formal) %d:%s", arg.val ,arg.id); break;
               case local_a        : sprintf(str, "|03(local) %d:%s", arg.val ,arg.id); break;
               case bool_a         : sprintf(str, "|06(boolean) %d:%s", arg.val ,arg.id); break;
               case retval_a       : sprintf(str, "|10(retval)") ; break;
               case nil_a          : sprintf(str, "|07(NULL)"); break;
               case number_a       : sprintf(str, "|04(num) %d:%f", arg.val, numConsts[arg.val]); break;
               case string_a       : sprintf(str, "|05(string) %d:%s", arg.val, stringConsts[arg.val]); break;
               case userfunc_a     : sprintf(str, "|08(userfunc) %d:%s", arg.val, userFuncs[arg.val].id); break;
               case libfunc_a      : sprintf(str, "|09(libfunc) %d:%s", arg.val,namedLibfuncs[arg.val]); break;
               default             : assert(0);
          }
          fprintf(fp, "%-30s", str);
}

void print_string(FILE* fp) {
     fprintf(fp, "\nstringConsts: \n");
     for (int i = 0; i < totalStringConsts; i++) {
          fprintf(fp, "%d\t", i);
          fprintf(fp, "|%s\n", stringConsts[i]);
     }
}

void print_num(FILE* fp) {
     fprintf(fp, "\nnumConsts: \n");
     for (int i = 0; i < totalNumConsts; i++) {
          fprintf(fp, "%d\t", i);
          fprintf(fp, "|%f\n", numConsts[i]);
     }
}

void print_libfuncs(FILE* fp) {
     fprintf(fp, "\nnamedLibFuncs: \n");
     for (int i = 0; i < totalNamedLibFuncs; i++) {
          fprintf(fp, "%d\t", i);
          fprintf(fp, "|%s\n", namedLibfuncs[i]);
     }
}

void print_userfuncs(FILE* fp) {
     fprintf(fp, "\nuserfuncs: \n");
     for (int i = 0; i < totaluserFuncs; i++) {
          fprintf(fp, "%d\t", i);
          fprintf(fp, "|%s: %d: %d\n", userFuncs[i].id, userFuncs[i].localSize, userFuncs[i].address);
     }
}

void print_consts(FILE* fp) {
     if ( totalStringConsts)  print_string(fp);
     if ( totalNumConsts)     print_num(fp);
     if ( totalNamedLibFuncs) print_libfuncs(fp);
     if ( totaluserFuncs)     print_userfuncs(fp);
}

void generate_bin() {
     char* opcodes[25] = {
     "assign",           "add",              "sub",
     "mul",              "div_v",            "mod",
     "uminus",           "and",              "or",
     "not",              "jeq",              "jne",
     "jle",              "jge",              "jlt",
     "jqt",              "callfunc",         "pusharg",
     "enterfunc",        "exitfunc",         "newtable",
     "tablegetelem",     "tablesetelem",     "jump",
     "nop"
     };
     FILE* fp = stdout;
     unsigned magic = 340200501;
     fp = fopen("mikriloulou.abc", "wb");
     fprintf(fp, "Magic: %d \n", magic);
     fprintf(fp, "N\t%-30s%-30s%-30s%-30s\n", "|op", " |res", " |arg1", " |arg2");
     for ( int i = 0; i < nextinstructionlabel(); i++) {
          vmarg res = (instructions + i)->result;
          vmarg arg1 = (instructions + i)->arg1;
          vmarg arg2 = (instructions + i)-> arg2;
          fprintf(fp, "%d\t", i);
          fprintf(fp, "|%-30s", opcodes[instructions[i].opcode]);
          print_instructions(fp, res);
          print_instructions(fp, arg1);
          print_instructions(fp, arg2);
          fprintf(fp, "\n");
     }
     print_consts(fp);
     fclose(fp);
}
