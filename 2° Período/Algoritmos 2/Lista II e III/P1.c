#include <stdio.h>

void teste(int numero, int i);

int main() {
    int vetor[15];
    int i;
    
    for (i = 0; i < 15; i++) {
        printf("Insira o valor de vetor[%i]", i);
        scanf("%i", &vetor[i]);
    }
    
    for (i = 0; i < 15; i++)
        teste(vetor[i], i); 

   printf("\n");
}

void teste(int numero, int i) {
    if(numero == 30)
        printf("\nElemento %i = 30", i);
}
