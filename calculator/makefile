main: lex.yy.c grammar.tab.h grammar.tab.c
	gcc lex.yy.c grammar.tab.h grammar.tab.c -lm -o main
lex.yy.c: lexis.l
	flex lexis.l
grammar.tab.h: grammar.tab.c
grammar.tab.c: grammar.y
	bison -d grammar.y
clean:
	rm -f grammar.tab.c grammar.tab.h
	rm -f lex.yy.c
	rm -f main
