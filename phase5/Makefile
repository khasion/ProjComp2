make:
	bison -v --yacc --defines vm_parser.y
	flex vm_yylex.l
	gcc -Werror -g lex.yy.c y.tab.c mem.c avm.c table.c relop.c arith.c functions.c -o runner
run:
	./Documents/Projects/hy340/ProjComp/ProjComp/calc bruh
	./runner ../mikriloulou.abc
clean:
	rm runner y.tab.c y.tab.h lex.yy.c y.output
