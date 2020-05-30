make:
	bison -v --yacc --defines vm_parser.y
	flex vm_yylex.l
	gcc -Werror -g lex.yy.c y.tab.c mem.c avm.c relop.c -o runner
clean:
	rm runner y.tab.c y.tab.h lex.yy.c
