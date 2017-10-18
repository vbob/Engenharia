//Int Linked List

#ifndef I_DOUBLYCIRCULAR_LINKEDLIST_H
#define I_DOUBLYCIRCULAR_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct iLinkedList {
    Node *first;
    Node *last;
    int size;
} iLinkedList;

void init(iLinkedList *list);
Node* addFirst(iLinkedList *list, int data);
Node* addLast(iLinkedList *list, int data);
Node* addPos(iLinkedList *list, int pos, int data);
int addArray(iLinkedList *list, int *array, int size);
Node* add(iLinkedList *list, int data);
Node* set(iLinkedList *list, int pos, int data);
int get(iLinkedList *list, int pos);
Node* getNode(iLinkedList *list, int pos);
int remFirst(iLinkedList *list);
int remLast(iLinkedList *list);
int remPos(iLinkedList *list, int pos);
int sIndex(iLinkedList *list, int data);
int isEmpty(iLinkedList *list);
void toArray(iLinkedList *list, int *array, int size);
int size(iLinkedList *list);
void show(iLinkedList *list);
void release(iLinkedList *list);

void init(iLinkedList *list) {
    list->first = list->last = NULL;
    list->size = 0;
}

Node* addFirst(iLinkedList *list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    newNode->data = data;

    if (isEmpty(list)) 
        list->first = newNode;
    else { 
        newNode->next = list->first;
        newNode->previous = list->first->previous;
        list->first->previous = newNode;
        list->first = newNode;
    }
    list->size++;
    return newNode;   
}

Node* addLast(iLinkedList *list, int data) {
    if (isEmpty(list)) return addFirst(list, data);

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;

    newNode->next = list->first;
    newNode->previous = list->first->previous;
    list->first->previous->next = newNode;
    list->first->previous = newNode;

    list->size++;
    return newNode;
}

Node* addPos(iLinkedList *list, int pos, int data) {
    if (pos<0 || pos>=list->size) return addLast(list, data);

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode = NULL) return NULL;
    newNode->data = data;

    Node* preNode = getNode(list, pos-1);
    newNode->previous=preNode;
    newNode->next=preNode->next;
    preNode->next->previous = newNode;
    preNode->next=newNode;

    list->size++;
    return newNode;
}

int addArray(iLinkedList *list, int *array, int size) {
    for (int i = 0; i<size; i++)
        addLast(list, array[i]);
}

Node* add(iLinkedList *list, int data) {
    if (isEmpty(list)) return addFirst(list, data);

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    newNode->data = data;
    
    Node* posNode = list->first;

    for (int i = 0; posNode->data<data; posNode=posNode->next, i++);
    newNode->previous=posNode;
    newNode->next=posNode->next;
    posNode->next->previous = newNode;
    posNode->next=newNode;

    list->size++;
    return newNode;
}

Node* set(iLinkedList *list, int pos, int data) {
    if (pos<0 || pos>=list->size) return addLast(list, data);
    Node *auxNode = getNode(list, pos);
    auxNode->data = data;
    return auxNode;
}

int get(iLinkedList *list, int pos) {
   if (pos<0 || pos>=list->size) return getNode(list,pos)->data;
   else return -1;
}

Node* getNode(iLinkedList *list, int pos){
    Node* posNode = list->first;
    for (int i = 0; i<=pos; posNode=posNode->next, i++);
    return posNode;
}

int remFirst(iLinkedList *list) {
    if (!isEmpty(list)) {
        Node *auxNode = list->first;
        list->first->previous->next=list->first->next;
        list->first->next->previous=list->first->previous->previous;
        list->first=list->first->next;
        free(auxNode);
        list->size--;
        return 0;
    }
    else return -1;
}

int remLast(iLinkedList *list) {
    if (list->size>1) {
        Node *auxNode = list->first->previous;
        auxNode->previous->next=list->first;
        auxNode->next->previous=auxNode->previous;
        free(auxNode);
        list->size--;
        return 0;
    }

    else return -1;
}

int remPos(iLinkedList *list, int pos) {
     if (pos<0 || pos>=list->size) return -1;
     if (pos==0) return remFirst(list);
     if (pos==list->size-1) return remLast(list);
     
     Node *auxNode = getNode(list,pos);
     auxNode->previous->next = auxNode->next;
     auxNode->next->previous = auxNode->previous;
     free(auxNode);
     list->size--;

     return 0;
}
int sIndex(iLinkedList *list, int data) {
    int i = 0;
     for (Node* posNode = list->first; posNode->data==data && i <= list->size+1; posNode=posNode->next, i++);
     if (i < list->size)
        return i;
     else   
        return -1;
}

int isEmpty(iLinkedList *list) {
    return list->size==0;
}

void toArray(iLinkedList *list, int *array, int size) {
    int i = 0;
    for (Node* posNode = list->first; i<list->size && i < size; posNode=posNode->next, i++)
        array[i]=posNode->data;
}

int size(iLinkedList *list) {
    return list->size;
}

void show(iLinkedList *list) {
    int i = 0;
    for (Node* posNode = list->first; i<list->size; posNode=posNode->next, i++)
        printf("Posicao %d - %d\n", i, posNode->data);
}

void release(iLinkedList *list) {
    for (int i = 0; i < list->size; i++)
        remFirst(list);
}

#endif