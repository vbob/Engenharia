//ID STACK

#ifndef PILHA_IDSTACK_H
#define PILHA_IDSTACK_H

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct iDStack {
    node *top;
    int size;
    int id;
} iDStack;

void init(iDStack *stack, int id);
int push(iDStack *stack, int data);
int pop(iDStack *stack);
int top(iDStack *stack);
int isEmpty(iDStack *stack);
int size(iDStack *stack);
void show(iDStack *stack);
void release(iDStack *stack);

void init(iDStack *stack, int id) {
    stack->top = NULL;
    stack->size = 0;
    stack->id = id;
}

int push(iDStack *stack, int data) {
    node *newNode = (node*) malloc(sizeof(node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return 1;
}

int pop(iDStack *stack) {
    if(!isEmpty(stack)) {
        node *oldNode = stack->top;
        stack->top = stack->top->next;
        stack->size--;
        int oldNodeData = oldNode->data;
        free(oldNode);
        return oldNodeData;
    } else return -1;
}

int top(iDStack *stack) {
    if(!isEmpty(stack))
        return stack->top->data;
    else return -1;
}

int isEmpty(iDStack *stack) {
    return stack->size==0;
}

int size(iDStack *stack) {
    return stack->size;
}

void show(iDStack *stack) {
    node *nodeAdress = stack->top;
    while (nodeAdress != NULL) {
        printf("%d\n", nodeAdress->data);
        nodeAdress = nodeAdress->next;
    }
}

void release(iDStack *stack) {
    if (!isEmpty(stack)) {
        node *oldNode;
        do {
            oldNode = stack->top;
            stack->top = stack->top->next;
            free(oldNode);
        } while(stack->top!=NULL);
        stack->size=0;
    }
}

#endif