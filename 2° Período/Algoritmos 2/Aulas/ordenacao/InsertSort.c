#include <stdio.h>
#define TAM 10

int main() {
	// Declaração das variáveis
	int i, j, aux;
	int lista[TAM]; 
	
	// Leitura da lista de numeros a serem ordenados
	for (i = 0; i < TAM; i++) {
		printf("Insira o valor %i da lista: ", i);
		scanf("%i", &lista[i]);
	}
	
	// Imprima a lista
	for (i = 0; i < TAM; i++) {
		printf("%i ", lista[i]);
	}
	
	// Ordenação da lista
	for (i=1; i <= TAM-1; i++) {
		aux = lista[i];
		j = i;
		while (j>0 && (lista[j-1] > aux)) {
			lista[j] = lista[j-1];
			j--;
		}
		lista[j] = aux;
	}
	
	// Imprima a lista
	printf("\n");
	for (i = 0; i < TAM; i++) {
		printf("%i ", lista[i]);
	}
}
