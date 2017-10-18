//Hash Dictionary Library

#ifndef I_HASH_H
#define I_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iLinkedList.h"

#define KEY_SIZE 10
#define TABLE_SIZE 20

typedef struct hashTable {
    node table[TABLE_SIZE];
    int size;
    iLinkedList list;
} hashTable;

void hInit          (hashTable *hTable);
void *hGet          (HashTable *hTable, char *key);
int hPut            (HashTable *hTable, char key[], int value);
void hRemove        (HashTable *hTable, char key[]);
int hIsEmpty        (HashTable *hTable);
int hSize           (HashTable *hTable);
int setFirstValue   (HashTable *hTable, char *key);
int getHash         (char *key);

void hInit          (hashTable *hTable) {
    init(hTable->list);
    node* newnode = (node*) malloc(sizeof(node));
    newNode->previous = newNode;
    newNode->next = newNode;
    hTable->firstNode = newNode;
    hTable->size = 0;
}

void *hGet          (HashTable *hTable, char *key) {
    node auxNode = hTable->table[getHash(key)];
    while (auxNode->key != key)
        auxNode = auxNode->next;
    return auxNode->value;
}

int hPut            (HashTable *hTable, char key[], int value) {
    addFirst(hTable->list, value);
    int tablePos = getHash(key);
    while (hTable->table[tablePos] != NULL)
        tablePos++;
    hTable->table[tablePos] = getNode(hTable->list, 0);
    hTable->size++;
    return 1;
}

void hRemove        (HashTable *hTable, char key[]) {
    int tablePos = getHash(key);
    while (hTable->table[tablePos] != NULL)
        tablePos++;
    int i = 0;
    for (int i = 0; hTable->list[tablePos]->value != get(hTable->list, i); i++);
    remove(hTable->list, i);
    hTable->table[i]=NULL;
    hTable->size--;
    return 1;
}

int hIsEmpty        (HashTable *hTable) {
    return hTable->size == 0;
}

int hSize           (HashTable *hTable) {
    return hTable->size;
}

int getHash         (char *key) {
    int hash = 0;
    for (int i = 0; i < KEY_SIZE; i++)
        hash += key[i]*(i+1);
    return hash%TABLE_SIZE;
}


#endif
