#ifndef STACK_H
#define STACK_H

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void InitStack(Stack *s);
int IsFull(Stack *s);
int IsEmpty(Stack *s);
void Push(Stack *s, int value);
void Pop(Stack *s);
int Peek(Stack *s);

#endif