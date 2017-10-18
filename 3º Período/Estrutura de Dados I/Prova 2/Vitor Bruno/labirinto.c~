// labirinto do Aluno Vitor Bruno de Oliveira Barth

#include "iQueue.h"
#include <stdlib.h>

#define TAMANHO 10

int main() {
	iQueue X, Y;
	init(&X, 0);
	init(&Y, 0);

	enqueue(&X, 0);
	enqueue(&Y, 0);

	int labirinto[10][10] = {
		  	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
		  	{1, 0, 0, 0, 0, 1, 0, 0, 1, 0},
			{1, 1, 1, 1, 0, 1, 0, 1, 1, 0},
			{1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
			{1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
			{0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
			{1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
			{1, 1, 0, 1, 0, 1, 1, 1, 0, 1}
	};

	int C = labirinto[0][0]; // C -> Valor que indica o caminho

	do {
		if(labirinto[peek(&X)+1][peek(&Y)] == C && peek(&X)+1 < SIZE-2) {
			enqueue(&X, peek(&X)+1);
			enqueue(&Y, peek(&Y));	
		}

		if(labirinto[peek(&X)-1][peek(&Y)] == C  && peek(&X)-1 >= 0) {
			enqueue(&X, peek(&X)-1);
			enqueue(&Y, peek(&Y));	
		}

		if(labirinto[peek(&X)][peek(&Y)+1] == C && peek(&Y)+1 < SIZE-2) {
			enqueue(&X, peek(&X));
			enqueue(&Y, peek(&Y)+1);	
		}	
	
		if(labirinto[peek(&X)][peek(&Y)-1] == C && peek(&Y)-1 >= 0) {
			enqueue(&X, peek(&X));
			enqueue(&Y, peek(&Y)-1);	
		}

		if (!isEmpty(&X)) 
			labirinto[peek(&X)][peek(&Y)] = C-1;

		printf("\n(%d, %d)", dequeue(&X), dequeue(&Y));

	} while ((peek(&X) != SIZE && peek(&Y) != SIZE) && !isEmpty(&X));
	
}

