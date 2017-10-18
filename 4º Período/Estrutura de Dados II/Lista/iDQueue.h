//ID STACK

#ifndef FILA_IDQUEUE_H
#define FILA_IDQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct iDQueue {
	int size;
    node *top;
} iDQueue;

void init(iDQueue *queue);
int enqueue(iDQueue *queue, int data);
int dequeue(iDQueue *queue);
int peek(iDQueue *queue);
int isEmpty(iDQueue *queue);
int size(iDQueue *queue);
void show(iDQueue *queue);
void release(iDQueue *queue);

void init(iDQueue *queue) {
    queue->top = NULL;
    queue->size = 0;
}

int enqueue(iDQueue *queue, int data) {
    node *newNode = (node*) malloc(sizeof(node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    node *lastNode;
    while(lastNode->next->next!=NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
    queue->size++;
    return 1;
}

int dequeue(iDQueue *queue) {
    if(!isEmpty(queue)) {
        node *firstNode = queue->top;
        queue->top = queue->top->next;
        queue->size--;
        int firstNodeData = firstNode->data;
        free(firstNode);
        return firstNodeData;
    } else return -1;;
}

int peek(iDQueue *queue) {
    if(!isEmpty(queue)) {
        return queue->top->data;
    } else return -1;
}

int isEmpty(iDQueue *queue) {
    return queue->size==0;
}

int size(iDQueue *queue) {
    return queue->size;
}

void show(iDQueue *queue) {
    node *nodeAdress = queue->top;
    while (nodeAdress != NULL) {
        printf("%d\n", nodeAdress->data);
        nodeAdress = nodeAdress->next;
    }
}

void release(iDQueue *queue) {
    if (!isEmpty(queue)) {
        node *oldNode;
        do {
            oldNode = queue->top;
            queue->top = queue->top->next;
            free(oldNode);
        } while(queue->top!=NULL);
        queue->size=0;
    }
}

#endif