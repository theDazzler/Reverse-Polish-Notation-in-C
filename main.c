//Name:Devon Guinane
//Reads expression from user in Reverse Polish Notation (1 2 3 + * =)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//read expression from user
void getInput()
{
	char ch;
	
	while(1)
	{
		//clear the stack before user enters expression
		makeEmpty();
		
		printf("Enter an RPN expression: ");
		
		//read character from input
		scanf("%c", &ch);
		
		//exit program if user enters 'q'
		if(ch == 'q')
				break;

		//parse all characters until a newline is reached
		while(1)
		{	
			if(ch == '\n')
				break;
			
			//if character is an integer
			if(ch >= 48 && ch <= 57)
			{
				if(!isFull())
				{
					//convert char to int and push integer onto stack
					push(ch - 48);
				}
				else
				{
					//stack ran out of space, print error and exit program
					printf("Expression is too complex\n");
					exit(EXIT_FAILURE);
				}
				
			}
			
			switch(ch)
			{
				case '+':
					push(add(pop(), pop()));
					break;
				case '-':
					push(sub(pop(), pop()));
					break;
				case '*':
					push(mul(pop(), pop()));
					break;
				case '/':
					push(divide(pop(), pop()));
					break;
				case '=':
					printf("%d\n", pop());
					break;
			}
				
			//get next character
			scanf("%c", &ch);
		}
	}
}

//adds 2 integers
int add(int a, int b)
{
	return a + b;
}

//subtracts 2 integers
int sub(int a, int b)
{
	return a - b;
}

//multiplies 2 integers
int mul(int a, int b)
{
	return a * b;
}

//divides 2 integers
int divide(int a, int b)
{
	return a / b;
}

int main()
{

	getInput();
	//printf("%d\n", pop());

	return 0;
}
