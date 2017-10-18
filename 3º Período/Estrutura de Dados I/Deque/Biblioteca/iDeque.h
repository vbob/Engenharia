/*
 * iDeque.h
 *
 *  Created on: 11 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *
 *  Um deque é um conjunto de itens a partir do qual podem ser eliminados e inseridos
 *  itens em ambas as extremidades. Chame as duas extremidades de um deque esq e dir.
 *  Como  um  deque  pode  ser  representado  como  um  vetor  em  C? Escreva  quatro
 *  funções em C, RemDir, RemEsq, InsDir, InsEsq, para remover e inserir elementos nas
 *  extremidades esquerda e direita de um deque.
 *  Certifique-se de que as funções funcionem corretamente para o deque vazio e detectem
 *  o estouro e o underflow (tentativa de remoção quando a fila está vazia).
 *
 */
#include <stdio.h>

#ifndef FILA_IDEQUE_H_
#define FILA_IDEQUE_H_

#define SIZE 10

typedef struct iDeque {
    int elements[SIZE];
    int beggining;
    int size;
    int end;
    int id;
}iDeque;

void init(iDeque *deque);
void enqueue(iDeque *deque, int element);
int dequeue(iDeque *deque);
void push(iDeque *deque, int element);
int pop(iDeque *deque);
int addFront(iDeque *deque, int element);
int peek(iDeque *deque);
int top(iDeque *deque);
int isEmpty(iDeque *deque);
int isFull(iDeque *deque);
int size(iDeque *deque);
int capacity(iDeque *deque);
void show(iDeque *deque);
int get(iDeque *deque, int i);

void init(iDeque *deque) {
    deque->beggining = 0;
    deque->end = 1;
    deque->size = 0;
}

void enqueue(iDeque *deque, int element) {
    if (!isFull(deque)) {
        deque->elements[deque->end-1] = element;
        if(deque->end == SIZE) 
            deque->end=0;
        deque->end++;
        deque->size++;
    }

    else
        printf("CAN'T ENQUEUE, DEQUE IS FULL");
}

int dequeue(iDeque *deque) {
    if(!isEmpty(deque)) {
        if(deque->beggining == SIZE-1) {
            deque->beggining = 0;
            deque->size--;
            return deque->elements[SIZE-1];
        } 

        else
            return deque->beggining++;
    }

     else
        printf("CAN'T DEQUEUE, DEQUE IS EMPTY");
}

void push(iDeque *deque, int element) {
    if (!isFull(deque)) {
        deque->elements[deque->end-1] = element;
        if(deque->end == SIZE) 
            deque->end=0;
        deque->size++;
        deque->end++;
    }

    else
        printf("CAN'T PUSH, DEQUE IS FULL");
}

int pop(iDeque *deque) {
    if(!isEmpty(deque)) {
        deque->size--;

        if(deque->end == 1) {
            deque->end = SIZE;
            return deque->elements[0];
        }

        else
            return deque->end--;
    }

     else
        printf("CAN'T POP, DEQUE IS EMPTY");   
}

int addFront(iDeque *deque, int element) {
    if(!isFull(deque)) {
        if(deque->beggining = 0)
            deque->beggining = SIZE-1;
        deque->elements[deque->beggining] = element;
        deque->size++;
    }

    else
        printf("CAN'T ADDFRONT, DEQUE IS FULL");
}

int peek(iDeque *deque) {
    if(isEmpty(deque)) {
        printf("CAN'T PEEK, DEQUE IS EMPTY");   
        return -1;
    }

    return deque->elements[deque->end-1];
}

int top(iDeque *deque) {
    if(isEmpty(deque)) {
        printf("CAN'T TOP, DEQUE IS EMPTY");   
        return -1;
    }

    return deque->elements[deque->beggining];
}

int isEmpty(iDeque *deque) {
    return deque->size == 0;
}
int isFull(iDeque *deque) {
    return deque->size == SIZE;
}
int size(iDeque *deque) {
    return deque->size;
}
int capacity(iDeque *deque) {
    return  SIZE - deque->size;
}
void show(iDeque *deque) {
    while(!isEmpty(deque)) 
        printf("\n %i", pop(deque));
}

int get(iDeque *deque, int i) {
    if (i > SIZE-1) {
    
        if(deque->beggining + i > SIZE-1) {
            i = (deque->beggining + i) - SIZE;
        }

    return deque->elements[i];
    
    }
    
    else {
        printf("OUT OF RANGE");
        return -1;
    }
}

#endif /* FILA_IDEQUE_H_ */
