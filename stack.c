#include "stack.h"

void InitStack(Stack *s) {
    s->top = -1;
}

int IsFull(Stack *s) {
    return s->top == MAX - 1;
}

int IsEmpty(Stack *s) {
    return s->top == -1;
}

void Push(Stack *s, int value) {
    if (!IsFull(s)) {
        s->top++;
        s->data[s->top] = value;
    }
}

void Pop(Stack *s) {
    if (!IsEmpty(s)) {
        s->top--;
    }
}

int Peek(Stack *s) {
    if (!IsEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}