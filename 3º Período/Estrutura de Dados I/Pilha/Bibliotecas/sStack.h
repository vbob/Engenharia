/**************************************************************************
 * Biblioteca de Pilha		                                              *
 *                                                                        *
 * Biblioteca com operações de pilha							 		  *
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/

#ifndef SSTACK_H_
#define SSTACK_H_

#define SIZE 10

typedef struct sStack {
    char *elements[SIZE];
    int top;
    int id;
}sStack;

void init(sStack *stack, int id);
void push(sStack *stack, char *element);
char* pop(sStack *stack);
char* top(sStack *stack);
int isEmpty(sStack *stack);
int isFull(sStack *stack);
int size(sStack *stack);
int capacity(sStack *stack);
void show(sStack *stack);

void init(sStack *stack, int id) {
    stack->top = -1;
    stack->id = id;
}

void push(sStack *stack, char *element) {
    if (!isFull(stack)) {
        stack->top++;
        stack->elements[stack->top]=element;
    } else
        printf("Push not allowed: stack is full.\n");
}

char* pop(sStack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        return stack->elements[stack->top+1];
    } else {
        printf("Pop not allowed: stack is empty.\n");
        return "";
    }
}

char* top(sStack *stack) {
	return (isEmpty(stack))?" ":stack->elements[stack->top];
}

int isEmpty(sStack *stack) {
    return stack->top==-1;
}

int isFull(sStack *stack) {
    return stack->top==SIZE-1;
}

int size(sStack *stack) {
    return stack->top+1;
}

int capacity(sStack *stack) {
    return SIZE;
}

void show(sStack *stack) {
    while (!isEmpty(stack)) {
        printf("%s", pop(stack));
    }
}

#endif /* SSTACK_H_ */
