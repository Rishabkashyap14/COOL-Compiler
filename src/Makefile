all: lex.yy.o y.tab.o symbolTable.o typeChecking.o codeOptimization.o cfg.o
	gcc -g -Wall lex.yy.o y.tab.o symbolTable.o typeChecking.o codeOptimization.o cfg.o -o test.out -ll
	
lex.yy.o:
	gcc -g -c lex.yy.c

y.tab.o:
	gcc -g -c y.tab.c

symbolTable.o:
	gcc -g -c symbolTable.c
	
typeChecking.o:
	gcc -g -c typeChecking.c

codeOptimization.o:
	gcc -g -c codeOptimization.c

cfg.o:
	gcc -g -c cfg.c

clean:
	rm -f *.o *.out
