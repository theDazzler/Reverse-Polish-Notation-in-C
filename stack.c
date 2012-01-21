//this implementation does NOT expand its capacity when it is full

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = 0;

void makeEmpty()
{
	top = 0;	
}

bool isEmpty()
{
	return top == 0;
}

bool isFull()
{
	return top == MAX_SIZE;	
}

void push(int value)
{
	stack[top++] = value;
}

int pop()
{
	if(isEmpty())
	{
		printf("Not enough operands in expression\n");
		exit(EXIT_FAILURE);
	}
	return stack[--top];	
}

int getCurrentSize()
{
	return top;
}
