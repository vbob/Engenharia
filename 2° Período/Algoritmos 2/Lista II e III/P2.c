#include <stdio.h>

void teste(int numero);

int main() {
    int vetor[50];
    int i;
    
    for (i = 0; i < 50; i++) {
        printf("Insira o valor de vetor[%i]", i);
        scanf("%i", &vetor[i]);
    }
	
	printf("\nOs valores positivos do vetor sao: ");    


    for (i = 0; i < 50; i++) {
        teste(vetor[i]);
    }

	printf("\n");
}

void teste(int numero) {
    if (numero > 0)
        printf("%i ", numero);
}
