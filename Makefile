make:
	bison -v --yacc --defines parser.y
	flex alpha_yylex.l
	gcc -Wall -Werror -g lex.yy.c y.tab.c table.c quads.c stack.c avm.c mem.c -o calc
clean:
	rm calc y.tab.c lex.yy.c y.tab.h y.output
