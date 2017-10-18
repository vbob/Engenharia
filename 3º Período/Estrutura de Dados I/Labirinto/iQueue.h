// iQueue do Aluno Vitor Bruno de Oliveira Barth

#define SIZE 1000

#ifndef IQUEUE_H
#define IQUEUE_H


#include <stdio.h>

typedef struct {
	int elements[SIZE];
	int size;
	int begin;
	int end;
	int id;
} iQueue;

void init(iQueue *queue, int id);
void enqueue(iQueue *queue, int element);
int dequeue(iQueue *queue);
int peek(iQueue *queue);
int isEmpty(iQueue *queue);
int isFull(iQueue *queue);
int size(iQueue *queue);
int capacity(iQueue *queue);
void show(iQueue *queue);

void init(iQueue *queue, int id) {
	queue->size=queue->begin=queue->end=0;
	queue->id = id;
}

void enqueue(iQueue *queue, int element) {
	if(!isFull(queue)) {
		queue->elements[queue->end]=element;
		queue->end++;
		if (queue->end==SIZE)
			queue->end = 0;
		queue->size++;
	}

	else
		printf("\nCAN'T ENQUEUE, QUEUE IS FULL\n");
}

int dequeue(iQueue *queue) {
	if(!isEmpty(queue)) {
		queue->size--;
		if(queue->begin==SIZE-1) {
			queue->begin=0;
			return queue->elements[SIZE-1];
		}
		
		else
			return queue->elements[queue->begin++];
	}

	else {
		printf("\nCAN'T DEQUEUE, QUEUE IS EMPTY\n");
		return -1;
	}
}

int peek(iQueue *queue) {
	if(!isEmpty(queue)) {
		return queue->elements[queue->begin];
	}

	else {
		printf("\nCAN'T PEEK, QUEUE IS EMPTY\n");
		return -1;
	}
}

int isEmpty(iQueue *queue) {
	return queue->size==0;
}

int isFull(iQueue *queue) {
	return queue->size==SIZE;
}
int size(iQueue *queue) {
	return queue->size;
} 

int capacity(iQueue *queue) {
	return SIZE-queue->size;
}

void show(iQueue *queue) {
	while(!isEmpty(queue))
		printf("\n%d", dequeue(queue));
}

#endif
