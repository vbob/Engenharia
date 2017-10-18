#ifndef GENLIST_H
#define GENLIST_H

#include <stdio.h>

typedef struct Node {
    int type; // 0 for Atom, 1 for List
    union {
        int atom;
        struct Node *list;
    } data;
    struct Node *next;
} Node;

int addAtom(Node *list, int data); // *list has to be the adress of a new empty node
int addList(Node *list, Node *subList);
Node *head(Node *list);
Node *tail(Node *list);
void print(Node *list);
int depht(Node *list);

int addAtom(Node *list, int data) {
    Node *cache = (Node*) malloc(sizeof(Node*));
    cache->type = 0;
    cache->data.atom = data;
    list = *cache;
}

#endif