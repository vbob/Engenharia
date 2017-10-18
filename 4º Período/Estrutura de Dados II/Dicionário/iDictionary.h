//Dictionary Library

#ifndef I_DICTIONARY_H
#define I_DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 50

typedef struct node {
    struct node *next;
    struct node *previous;
    char key[KEY_SIZE];
    void *value;
} node;

typedef struct Dictionary {
    node *firstNode;
    void *firstValue;
    int size;
} Dictionary;

void dInit           (Dictionary *dictionary);
void *dGet           (Dictionary *dictionary, char *key);
node *getPrevious     (Dictionary *dictionary, char *key);
node* getKeys       (Dictionary *dictionary);
void* getValues     (Dictionary *dictionary);
int put             (Dictionary *dictionary, char key[], void *value);
void dRemove         (Dictionary *dictionary, char key[]);
int dIsEmpty         (Dictionary *dictionary);
int dSize            (Dictionary *dictionary);
int setFirstValue   (Dictionary *dictionary, char *key);

void dInit           (Dictionary *dictionary) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->previous = new_node;
    new_node->next = new_node;
    dictionary->firstNode = new_node;
    dictionary->size = 0;
}

void *dGet           (Dictionary *dictionary, char *key) {
    if (dSize(dictionary) == 0) return dictionary->firstNode;

    node* testNode = dictionary->firstNode; 

    do {
        if (testNode->key == key)
            return testNode;
        else
            testNode = testNode->next;
    } while (testNode != dictionary->firstNode);

    return dictionary->firstNode;
}

node *getPrevious     (Dictionary *dictionary, char *key) {    
    if (dSize(dictionary) == 0) return dictionary->firstNode;
    
    node* testNode = dictionary->firstNode; 

    do {
        if (testNode->next->key >= key)
            return testNode;
        else
            testNode = testNode->next;
    } while (testNode != dictionary->firstNode);

    return dictionary->firstNode;
}

node* getKeys       (Dictionary *dictionary) {
    return dictionary->firstNode;
}
void* getValues     (Dictionary *dictionary) {
    return dictionary->firstValue;
}

int put             (Dictionary *dictionary, char key[], void *value) {
    node* newNode = (node*) malloc(sizeof(node));
    node* previousNode = getPrevious(dictionary, key);

    if (key == previousNode->next->key)
        return -1;

    strcpy(newNode->key, key);
    newNode->value = value;

    if (dSize(dictionary) == 0) {
        previousNode->previous = newNode;
        dictionary->firstNode = newNode;
    }
    
    previousNode->next->previous = newNode;
    previousNode->next = newNode;

    return 0;
}

void dRemove         (Dictionary *dictionary, char key[]) {
    node* previousNode = getPrevious(dictionary, key);
    node* toBeRemovedNode = previousNode->next;
    previousNode->next = toBeRemovedNode->next;
    toBeRemovedNode->previous = previousNode;
    free(toBeRemovedNode);
}

int dIsEmpty         (Dictionary *dictionary) {
    return dSize(dictionary) == 0;
}

int dSize            (Dictionary *dictionary) {
    return dictionary->size;
}

int setFirstValue   (Dictionary *dictionary, char *key) {
    if (dSize(dictionary) > 0)
        dictionary->firstValue = dGet(dictionary, key);
    else 
        return -1;

    return 0;
}


#endif
