//BIBLIOTECA FILA VITOR BRUNO

#include <stdio.h>

#ifndef FILA_IQUEUE_H
#define FILA_IQUEUE_H

#define SIZE 200

typedef struct iQueue {
	int elements[SIZE];
	int end;
	int beginning;
	int nElements;
} iQueue;

void init(iQueue *queue);
void enqueue(iQueue *queue, int element); // Adiciona elemento na posicao N
int dequeue(iQueue *queue); // Remove o primeiro elemento e manda os outros pra frente
int peek(iQueue *queue); // Mostra a primeira posicao
int isEmpty(iQueue *queue); 
int isFull(iQueue *queue);
int size(iQueue *queue); // Numero de elementos
int capacity(iQueue *queue); // Quantos elementos suporta
void show(iQueue *queue); // Loop de dequeue

void init(iQueue *queue) {
	queue->end = 0;
	queue->beginning = -1;
	queue->nElements = 0;
}

void enqueue(iQueue *queue, int element) {
	if (!isFull(queue)) {
		queue->elements[queue->end] = element;
		queue->end++;
		queue->nElements++;		
		if (queue->end == SIZE)
			queue->end = 0;	
	}
	
	else 
		printf("CAN'T ENQUEUE! QUEUE IS FULL\n");
}

int dequeue(iQueue *queue) {
	if (!isEmpty(queue)) {
		queue->nElements--;
		if (queue->beginning == SIZE-2) {
			queue->beginning = -1;		
			return queue->elements[SIZE-1];
		}	
		queue->beginning = queue->beginning+1;	
		return queue->elements[queue->beginning];
	}

	else {
		printf("CAN'T DEQUEUE! QUEUE IS EMPTY\n");
		return -1;
	}
}

int peek(iQueue *queue) {
	return queue->elements[queue->beginning+1];
}

int isEmpty(iQueue *queue) {
	return queue->nElements == 0;
}

int isFull(iQueue *queue) {
	return queue->nElements==SIZE;
}

int size(iQueue *queue) {
	return queue->nElements;
}

int capacity(iQueue *queue) {
	return SIZE;
}

void show(iQueue *queue) {
	while (!isEmpty(queue))
		printf("%i \n", dequeue(queue));
}

#endif
