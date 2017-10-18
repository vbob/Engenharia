//Biblioteca sDoubleStack.h de VITOR BRUNO DE OLIVEIRA BARTH

#ifndef SDOUBLESTACK_H
#define SDOUBLESTACK_H

#define SIZE 10

#include <string.h>
#include <stdio.h>

// STRUCT DECLARATION
typedef struct sDoubleStack {
	char values[SIZE][100]; // Duas dimensões, pois string é um vetor de chars
	int top[2]; // TOPO[0] é o topo da 1a pilha e TOPO[1] é o topo da 2a pilha; IDs serão 1 e 2
} sDoubleStack ;

// SUBROUTINE DECLARATION
void sdInit(sDoubleStack *stack, int idStack); // Coloca o topo[0] = -1 e topo[1] = SIZE
void sdPush(sDoubleStack *stack, char *element, int idStack); // Se stack[id] não cheia, salva o elemento em values[topo++] ou values[topo--]
char* sdPop(sDoubleStack *stack, int idStack); // Se stack[id] não vazia, decrementa o topo e retorna values[topo+1]
char* sdTop(sDoubleStack *stack, int idStack); // Retorna stack[id].values[topo]
int sdIsEmpty(sDoubleStack *stack, int idStack); // Retorna true se topo == -1 ou topo == SIZE
int sdIsFull(sDoubleStack *stack); // Retorna true se SIZE-1-topo[0]-topo[1] == 0
int sdSize(sDoubleStack *stack); // Retorna SIZE
int sdCapacity(sDoubleStack *stack); // Retorna SIZE-1-topo[0]-topo[1]
void sdShow(sDoubleStack *stack, int idStack); // Enquanto stack[id] não vazia, imprime o pop

// SUBROUTINE CODE
void sdInit(sDoubleStack *stack, int idStack) {
	if (idStack == 0)
		stack->top[0] = -1;
	else if (idStack == 1)
		stack->top[1] = SIZE;
	else
		printf("CAN'T INIT! INVALID STACK ID");
}

void sdPush(sDoubleStack *stack, char *element, int idStack) {
	if(!sdIsFull(stack)) {
		if(idStack == 1)
			strcpy(stack->values[stack->top[0]++], element);
		else if(idStack == 2)
			strcpy(stack->values[stack->top[1]--], element);
		else
			printf("CAN'T PUSH! INVALID STACK ID");
	}

	else
		printf("ERROR! CAN'T PUSH, STACK IS FULL");
}

char* sdPop(sDoubleStack *stack, int idStack) {
	if(!sdIsEmpty(stack, idStack)) {
		if(idStack == 1) {
			stack->top[0]--;
			return stack->values[stack->top[0]+1];
		}
		else if(idStack == 2) {
			stack->top[1]++;
			return stack->values[stack->top[1]-1];
		}
		else {
			printf("CAN'T POP! INVALID STACK ID");
			return "-1";
		}
	}

	else {
		printf("ERROR! CAN'T POP, STACK IS EMPTY");
		return "-1";
	}
}

char* sdTop(sDoubleStack *stack, int idStack) {
	if(!sdIsEmpty(stack, idStack)) {
		if(idStack == 1)
			return stack->values[stack->top[0]];
		else if(idStack == 2)
			return stack->values[stack->top[1]];
		else {
			printf("CAN'T SHOW TOP! INVALID STACK ID");
			return "-1";
		}
	}
	else {
		printf("ERROR! CAN'T SHOW TOP, STACK IS EMPTY");
		return "-1";
	}
}

int sdIsEmpty(sDoubleStack *stack, int idStack) {
	if (idStack == 1)
		return stack->top[0] == -1;
	else if (idStack == 2)
		return stack->top[1] == SIZE;
	else {
		printf("ERROR! CAN'T SAY IT'S EMPTY, INVALID STACK ID");
		return -1;
	}
}

int sdIsFull(sDoubleStack *stack) {
	return (stack->top[0]-stack->top[1]-1-SIZE)==0;
}

int sdSize(sDoubleStack *stack) {
	return SIZE;
}

int sdCapacity(sDoubleStack *stack) {
	return stack->top[0]-stack->top[1]-1-SIZE;
}

void sdShow(sDoubleStack *stack, int idStack) {
	if (idStack == 1 || idStack == 2) {
		while (!sdIsEmpty(stack, idStack))
			printf(" %s \n", sdPop(stack, idStack));
	}
	else
		printf("ERROR! CAN'T SHOW, INVALID STACK ID");
}

#endif
