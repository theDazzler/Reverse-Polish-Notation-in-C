main:	main.o stack.o
	gcc -o main main.o stack.o -std=c99
	
main.o:	main.c stack.h
	gcc -c main.c -std=c99
	
stack.o:stack.c stack.h
	gcc -c stack.c -std=c99

