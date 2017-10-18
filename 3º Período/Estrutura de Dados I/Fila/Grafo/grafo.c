#include "../Bibliotecas/iQueue.h"
#include <stdlib.h>

#define N 6

void zerarMatriz(int cidades[N][N]);
void retornarDistancias(int cidades[N][N], int origem);
void zerarVetor(int vetor[N]);

int main() {
	int cidades[N][N];

	zerarMatriz(cidades);
	
	//cidades[ORIGEM][DESTINO]
	cidades[4][0] = cidades[0][1] = cidades[5][1] = cidades[3][4] = cidades[1][2] = cidades[3][2] = cidades[2][4] = 2;	

	int origem = 3;

	retornarDistancias(cidades, origem);

	return 0;
}

void zerarMatriz(int cidades[N][N]) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cidades[i][j] = 0;	
}

void zerarVetor(int vetor[N]) {
	for (int i = 0; i < N; i++) 
			vetor[i] = 99;	
}

void retornarDistancias(int cidades[N][N], int origem) {

	iQueue fila;
	init(&fila, 0);

	int vetorResultante[N];	
	zerarVetor(vetorResultante);

	enqueue(&fila, origem);
	vetorResultante[origem] = 0;	

	int temp = origem;


	while(!isEmpty(&fila)) {
		origem = dequeue(&fila);
		
		for (int i = 0; i < N; i++) {
			if (cidades[origem][i] != 0) {
				if (vetorResultante[i] > vetorResultante[origem]+cidades[origem][i]) {
					vetorResultante[i] = vetorResultante[origem]+cidades[origem][i];
					enqueue(&fila, i);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (vetorResultante[i] != 99)
			printf("A distancia de %i a %i é: %i\n", temp, i, vetorResultante[i]);
		else
			printf("Impossível chegar de %i a %i\n", temp, i);
			
	}				
}
