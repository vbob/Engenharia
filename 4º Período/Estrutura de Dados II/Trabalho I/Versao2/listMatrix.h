// Escrita por Vitor Bruno de Oliveira Barth em 23/01/2016
// Armazena informações do tipo string em uma matriz de listas

#ifndef LISTMATRIX_H
#define LISTMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEY_SIZE 40   // Tamanho máximo da string
#define MATRIX_HW 32  // Tamanho do lado da matriz
#define MATRIX_SIZE MATRIX_HW*MATRIX_HW // Como a matriz é quadrada, o tamanho dela é lado ao quadrado

typedef struct Node {
  char key[KEY_SIZE]; // Armazena a string
  struct Node *next;  // Endereça o próximo nó
} Node;

typedef struct List {
  Node *firstNode;
  Node *lastNode;
  int  size;
} List;

typedef struct ListMatrix {
  List *matrix[MATRIX_HW][MATRIX_HW]; // Matriz de listas
  int size;                           // Quantidade de nós ligados a matriz
} ListMatrix;

void initList	(List *list); // Inicializa uma lista
void init       (ListMatrix *listMatrix); // Inicializa uma matriz de listas
void addKey     (char key[KEY_SIZE], ListMatrix *listMatrix);  // Adiciona uma palavra na estrutura
int genHash	(char key[KEY_SIZE]);  // Devolve a posição onde salvar a informação a partir da KEY
int listSize    (List *list); // Retorna o número de strings salvas numa lista

void initList		(List *list) {
  list->firstNode = list->lastNode = NULL;
  list->size=0;
}

void init       (ListMatrix *listMatrix) {
  for (int i = 0; i < MATRIX_HW; i++) {
    for (int j = 0; j < MATRIX_HW; j++) {
      List *cacheList = (List*) malloc(sizeof(List));
      listMatrix->matrix[i][j] = cacheList;
      initList(listMatrix->matrix[i][j]);
    }
  }
}

void addKey     (char key[KEY_SIZE], ListMatrix *listMatrix) {
  int hash = genHash(key);
  int position[2];
  position[0] = (int) hash/MATRIX_HW;
  position[1] = hash-(position[0]*32);
  Node *newNode = (Node*) malloc(sizeof(Node));
  strcpy(newNode->key, key);

  if (listMatrix->matrix[position[0]][position[1]]->size == 0)
    listMatrix->matrix[position[0]][position[1]]->firstNode = listMatrix->matrix[position[0]][position[1]]->lastNode = newNode;

  else {
    listMatrix->matrix[position[0]][position[1]]->lastNode->next = newNode;
    listMatrix->matrix[position[0]][position[1]]->lastNode = newNode;
  }

  //printf("Adicionada a palavra %s, hash %i, na posicao %i %i\n", key, hash, position[0], position[1]);

  listMatrix->matrix[position[0]][position[1]]->size++;
}

int genHash(char key[KEY_SIZE]) {
	int acumulator = 0;
	for (int i = 0; i < KEY_SIZE; i++)
		acumulator += (int)	(sin(key[i])*10000);
	return abs(acumulator % (MATRIX_SIZE));
}

int listSize    (List *list) {
  return list->size;
}

#endif
