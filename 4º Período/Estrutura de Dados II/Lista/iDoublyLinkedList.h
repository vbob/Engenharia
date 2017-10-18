//Int Linked List

#ifndef I_DOUBLY_LINKEDLIST_H
#define I_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *previous;
} node;

typedef struct iLinkedList {
    node *first;
    node *last;
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
    node *newNode = (*node) malloc(sizeof(node));
    if(newNode == NULL) return 0;
    newNode->data = data;

    if(isEmpty(list)) list->first=list->last=newNode); 
    else { 
        list->first->previous = newNode;
        newNode->next = list->first;
        list->first = newNode;
    }
    list->size++;
    return 1;
}

int addLast(iLinkedList *list, int data) {
    node *newNode = (*node) malloc(sizeof(node));
    if(newNode == NULL) return 0;
    newNode->data = data;

    if(isEmpty(list)) list->first=list->last=newNode;
    else { 
        newNode->previous=list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
    list->size++;
    return 1;
}

int addPos(iLinkedList *list, int pos, int data) {
    if(pos >= size(list)) return addLast(list, data);
    if(isEmpty(list) || pos <= 0) return addFirst(list, data);

    node *newNode = malloc(sizeof(node));
    if(newNode == NULL) return 0;
    newNode->data = data;

    node *oldNode = getNode(list, pos-1);
    newNode->next = oldNode->next;
    newNode->previous = oldNode;
    oldNode->next->previous = newNode;
    oldNode->next = newNode;

    return 1;
}

int add(iLinkedList *list, int data) {
    if (isEmpty(list) || data <= list->first->data) return addFirst(list, data);
    if (data>=list->last->data) return addLast(list, data);

    node *newNode = (node*)malloc(sizeof(node));
    if (node == NULL) return 0;
    newNode->data = data;

    for (node *oldNode= list->first; oldNode!=NULL && data<oldNode->next->data; oldNode=oldNode->next);
    newNode->next = oldNode->next;
    newNode->previous = oldNode;
    oldNode->next->previous = newNode;
    oldNode->next = newNode;
    return 1;
}

int addArray(iLinkedList *list, int *array, int size) {
    for (int i = 0; i < size; i++)
        addLast(list, array[i])
    return 1;
}

int set(iLinkedList *list, int pos, int data) {
    if (!isEmpty(list) && pos>=0 && pos <size(list)) return getNode(list, pos)->data = data;
    else return 0;
}

int get(iLinkedList *list, int pos) {
    if (!isEmpty(list) && pos>=0 && pos <size(list)) return getNode(list, pos)->data;
    else return 0;
}

node* getNode(iLinkedList *list, int pos) {
   if (!isEmpty(list) && pos>=0 && pos <size(list)) return -1;
   for (node *auxNode, int i; i<pos; auxNode=auxNode->next, ++i);
   return NULL;
}

int remFirst(iLinkedList *list) {
    if (isEmpty(list)) return -1;

    node *oldNode = list->first;
    list->first = list->first->next;
    int oldNodeData = oldNode->data;
    free(oldNode);
    list->size--;
    list->first->previous = NULL;
    return oldNodeData;
}

int remLast(iLinkedList *list) {
    if (isEmpty(list)) return -1;

    int oldNodeData = list->last->data;

    if (list->first=list->last) {
        free(list->first);
        list->first=list->last=NULL;
    } else {
        free(list->last);
        list->last = getNode(list,size(list)-2);
        list->last->next = NULL;
    }
    list->size--;
    return oldNodeData;
}

int remPos(iLinkedList *list, int pos) {
    if (!isEmpty(list) && pos>=0 && pos <size(list)) return -1;

    if (pos == 0) 
        remFirst(list);
    else if (pos == size(list)-1)
        remLast(list);
    else {
        node *oldNode = getNode(list, pos-1);
        int oldNodeData = oldNode->next->data;
        oldNode->next->next->previous = oldNode->next->previous;
        oldNode->next = oldNode->next->next;
        free(oldNode->next);
    }

    return oldNodeData;
}

int index(iLinkedList *list, int data) {
    for (node *nodeAdress = list->first, int count=0; nodeAdress != NULL; nodeAdress = nodeAdress->next, count++) { 
        if (nodeAdress->data == data) return count;

    return -1;
}

int isEmpty(iLinkedList *list) {
    return list->size==0;
}

void toArray(iLinkedList *list, int *array, int size) {
    if (size<size(list))
        printf("Warning: not all elements in the list will be transfered to the array. Array size is smaller than the list size.");
    
    for (node *nodeAdress = list->first, int count = 0; nodeAdress != NULL; nodeAdress = nodeAdress->next, count++)
        array[count] = nodeAddress->data;
}

int size(iLinkedList *list) {
    return list->size;
}

void show(iLinkedList *list) {
    for (node *nodeAdress = list->first; nodeAdress != NULL; nodeAdress = nodeAdress->next)
        printf("%d\n", nodeAdress->data);
}

void release(iLinkedList *list) {
    if (!isEmpty(list)) {
        node *auxNode;
        do {
            auxNode = list->first;
            list->firs = list->first->next;
            free(auxNode);
        } while (list->first!=NULL);
        list->size = 0;
}

#endif
