#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

void makeEmpty();

bool isEmpty();

bool isFull();

void push(int value);

int pop();

int getCurrentSize();

#endif
