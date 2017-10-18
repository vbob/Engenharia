#include <stdio.h>
#include <stdlib.h>
#include "iDeque.h"
#define QDISCOS 3

void mover(iDeque *origem, iDeque *destino);
void hanoi (int qte, iDeque *origem, iDeque *auxiliar, iDeque *destino);

int main() {
	iDeque pilha[3];	
	
	for (int i = 0; i < 3; i++)
		init(&pilha[i], i+1);

	for (int i = 0; i < QDISCOS; i++)
		push(&pilha[0], QDISCOS-i);

	hanoi(QDISCOS, &pilha[0], &pilha[1], &pilha[2]);

	return EXIT_SUCCESS;
}

void mover(iDeque *origem, iDeque *destino) {
	push(destino, pop(origem));
	printf("Movido o disco %i de P%i -> P%i\n", top(destino), origem->id, destino->id);
}

void hanoi (int qte, iDeque *origem, iDeque *auxiliar, iDeque *destino) {
	if (qte == 1)
		mover(origem, destino);
	else {
		hanoi(qte-1, origem, destino, auxiliar);
		hanoi(1, origem, auxiliar, destino);
		hanoi(qte-1, auxiliar, origem, destino);  
	}
}

