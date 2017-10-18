//Int Linked List

#ifndef I_DOUBLYCIRCULAR_LINKEDLIST_H
#define I_DOUBLYCIRCULAR_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *previous;
} node;

typedef struct iLinkedList {
    node *first;
    int size;
} iLinkedList;

void init(iLinkedList *list);
int addFirst(iLinkedList *list, int data);
int addLast(iLinkedList *list, int data);
int addPos(iLinkedList *list, int pos, int data);
int addArray(iLinkedList *list, int *array, int size);
int add(iLinkedList *list, int data);
int set(iLinkedList *list, int pos, int data);
int get(iLinkedList *list, int pos);
node* getNode(iLinkedList *list, int pos);
int remFirst(iLinkedList *list);
int remLast(iLinkedList *list);
int remPos(iLinkedList *list, int pos);
int index(iLinkedList *list, int data);
int isEmpty(iLinkedList *list);
void toArray(iLinkedList *list, int *array, int size);
int size(iLinkedList *list);
void show(iLinkedList *list);
void release(iLinkedList *list);

void init(iLinkedList *list) {
    list->first = list->last = NULL;
    list->size = 0;
}

int addFirst(iLinkedList *list, int data) {
    node* newNode = (*node) malloc(sizeof(node));
    if (newNode==NULL) return -1;
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
    return 0;   
}

int addLast(iLinkedList *list, int data) {
    if (isEmpty(list)) return addFirst(list, data);

    node* newNode = (*node) malloc(sizeof(node));
    if (newNode == NULL) return -1;
    newNode->data = data;

    newNode->next = list->first;
    newNode->previous = list->first->previous;
    list->first->previous->next = newNode;
    list->first->previous = newNode;

    list->size++;
    return 0;
}

int addPos(iLinkedList *list, int pos, int data) {
    if (pos<0 || pos>=list->size) return addLast(list, data);

    node* newNode = (*node) malloc(sizeof(node));
    if (newNode = NULL) return -1;
    newNode->data = data;

    node* preNode = getNote(list, pos-1);
    newNode->previous=preNode;
    newNode->next=preNode->next;
    preNode->next->previous = newNode;
    preNode->next=newNode;

    list->size++;
    return 0;
}

int addArray(iLinkedList *list, int *array, int size) {
    for (int i = 0; i<size; i++)
        addLast(array[i]);
}

int add(iLinkedList *list, int data) {
    if (isEmpty(list)) return addFirst(list, data);

    node* newNode = (*node) malloc(sizeof(node));
    if (newNode = NULL) return -1;
    newNode->data = data;

    for (int i = 0, node* posNode = list->first; posNode->data<data; posNode=posNode->next, i++);
    newNode->previous=posNode;
    newNode->next=posNode->next;
    posNode->next->previous = newNode;
    posNode->next=newNode;

    list->size++;
    return 0;
}

int set(iLinkedList *list, int pos, int data) {
    if (pos<0 || pos>=list->size) return addLast(list, data) {
        getNode(list,pos)->data = data;
        return 0;
    }
    else return -1;
}

int get(iLinkedList *list, int pos) {
   if (pos<0 || pos>=list->size) return getNode(list,pos)->data;
   else return -1;
}

node* getNode(iLinkedList *list, int pos){
    for (int i = 0, node* posNode = list->first; i<=pos; posNode=posNode->next, i++);
    return posNode;
}

int remFirst(iLinkedList *list) {
    if (!isEmpty(list)) {
        node *auxNode = list->first;
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
        node *auxNode = list->first->previous;
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
     
     node *auxNode = getNode(list,pos);
     auxNode->previous->next = auxNode->next;
     auxNode->next->previous = auxNode->previous;
     free(auxNode);
     list->size--;

     return 0;
}
int index(iLinkedList *list, int data) {
     for (node* posNode = list->first, int i; posNode->data==data && i <= list->size+1; posNode=posNode->next, i++);
     if (i < list->size)
        return i;
     else   
        return -1;
}

int isEmpty(iLinkedList *list) {
    return list->size==0;
}

void toArray(iLinkedList *list, int *array, int size) {
    for (node* posNode = list->first, int i; i<list->size && i < size; posNode=posNode->next, i++)
        array[i]=posNode->data;
    return 0;
}

int size(iLinkedList *list) {
    return list->size;
}

void show(iLinkedList *list) {
    for (node* posNode = list->first, int i; i<list->size; posNode=posNode->next, i++)
        printf("Posicao %d - %d\n", i, posNode->data);
}

void release(iLinkedList *list) {
    for (int i = 0; i < list->size; i++)
        remFirst(list);
}

#endif