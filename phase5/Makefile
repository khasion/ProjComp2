make:
	bison -v --yacc --defines vm_parser.y
	flex vm_yylex.l
	gcc -Werror -g lex.yy.c y.tab.c mem.c avm.c table.c relop.c arith.c functions.c conv.c -o runner
calc:
	cd ..; bison -v --yacc --defines parser.y
	cd ..; flex alpha_yylex.l
	cd ..; gcc -Wall -Werror -g lex.yy.c y.tab.c table.c quads.c stack.c avm.c mem.c -o calc
all:
	bison -v --yacc --defines vm_parser.y
	flex vm_yylex.l
	gcc -Werror -g lex.yy.c y.tab.c mem.c avm.c table.c relop.c arith.c functions.c -lm conv.c -o runner
	cd ..; bison -v --yacc --defines parser.y
	cd ..; flex alpha_yylex.l
	cd ..; gcc -Wall -Werror -g lex.yy.c y.tab.c table.c quads.c stack.c avm.c mem.c -o calc
run:
	cd ..; ./calc bruh
	./runner ../mikriloulou.abc
clean:
	rm runner y.tab.c y.tab.h lex.yy.c y.output
