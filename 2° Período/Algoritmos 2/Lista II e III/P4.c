#include <stdio.h>

void troca(int* vetor, int i);

void main() {
    int vetor[10], i;
    
    for(i = 0; i < 10; i++) {
        printf("Insira o valor de vetor[%i]", i);
        scanf("%i", &vetor[i]);
    }
    
    for(i =0; i < 4; i++)
        troca(vetor, i);
        
    for(i = 0; i < 10; i++)
        printf("%i ", vetor[i]); 

	printf("\n");
}

void troca(int* vetor, int i) {
     int aux = vetor[i];
     vetor[i] = vetor[9-i];
     vetor[9-i] = aux;    
}
    
