/**************************************************************************
 * Biblioteca de Pilha		                                              *
 *                                                                        *
 * Biblioteca com operações de pilha							 		  *
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/

#ifndef DSTACK_H_
#define DSTACK_H_

#define SIZE 100

typedef struct dStack {
    double elements[SIZE];
    int top;
    int id;
}dStack;

void init(dStack *stack, int id);
void push(dStack *stack, double element);
double pop(dStack *stack);
double top(dStack *stack);
int isEmpty(dStack *stack);
int isFull(dStack *stack);
int size(dStack *stack);
int capacity(dStack *stack);
void show(dStack *stack);

void init(dStack *stack, int id) {
    stack->top = -1;
    stack->id = id;
}

void push(dStack *stack, double element) {
    if (!isFull(stack)) {
        stack->top++;
        stack->elements[stack->top]=element;
    } else
        printf("Push not allowed: stack is full.\n");
}

double pop(dStack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        return stack->elements[stack->top+1];
    } else {
        printf("Pop not allowed: stack is empty.\n");
        return -1;
    }
}

double top(dStack *stack) {
    return isEmpty(stack)?-1:stack->elements[stack->top];
}

int isEmpty(dStack *stack) {
    return stack->top==-1;
}

int isFull(dStack *stack) {
    return stack->top==SIZE-1;
}

int size(dStack *stack) {
    return stack->top+1;
}

int capacity(dStack *stack) {
    return SIZE;
}

void show(dStack *stack) {
    while (!isEmpty(stack)) {
        printf("%d\n", pop(stack));
    }
}

#endif /* DSTACK_H_ */
