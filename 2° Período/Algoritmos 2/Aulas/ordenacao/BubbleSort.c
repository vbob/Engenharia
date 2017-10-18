#include <stdio.h>
#define TAM 10

int main() {
	// Declaração de variaveis
	int i, j, aux;
	int lista[TAM];
	
	// Leitura da lista de numeros a serem ordenados
	for (i = 0; i < TAM; i++) {
		printf("Insira o valor %i da lista: ", i);
		scanf("%c", &lista[i]);
	}
	
	// Imprima a lista
	for (i = 0; i < TAM; i++) {
		printf("%c ", lista[i]);
	}
	
	// Ordenação da lista
	for (i = 0; i < TAM-1; i++) {
		for (j = 0; j < TAM-1; j++) 
		{
			if (lista[j] > lista[j+1]) {
				aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}
	printf("\n");
	// Imprima a lista
	for (i = 0; i < TAM; i++) {
		printf("%c ", lista[i]);
	}
	
	return 0;
}
