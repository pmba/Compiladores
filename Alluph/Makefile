main: main.o auxiliar.o file.o list.o lexical.o stack.o syntactic.o grammar.o
	gcc main.o auxiliar.o file.o list.o lexical.o stack.o syntactic.o grammar.o -o alluph
	rm *.o

main.o: main.c
	gcc -c main.c

syntactic.o: sources/syntactic.c includes/syntactic.h
	gcc -c sources/syntactic.c

stack.o: sources/stack.c includes/stack.h
	gcc -c sources/stack.c

lexical.o: sources/lexical.c includes/lexical.h
	gcc -c sources/lexical.c

list.o: sources/list.c includes/list.h
	gcc -c sources/list.c

file.o: sources/file.c includes/file.h
	gcc -c sources/file.c

auxiliar.o: sources/auxiliar.c includes/auxiliar.h
	gcc -c sources/auxiliar.c

grammar.o: sources/grammar.c includes/grammar.h
	gcc -c sources/grammar.c

clean: 
	rm *.o