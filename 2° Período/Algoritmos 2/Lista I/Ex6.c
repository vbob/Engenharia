/* Ler 90 valores
	Numero de Indetificacao e Peso do Boi
	Escrever o numero e o peso do mais gordo e do mais magro */
	
#include <stdio.h>
#define NUMBOIS 90

int main() {
	// declare variaveis 
    int i, identificacao, maiorId, menorId;
	float peso, maiorPeso, menorPeso;
	
	// leia o primeiro 
    printf("Insira a identificacao de 1: ");
	scanf("%i", &maiorId);
	menorId = maiorId;
	printf("Insira o peso de 1: ");
    scanf("%f", &maiorPeso);
	menorPeso = maiorPeso;
	i = 1;
	// Loop
	do {
        i++;
        printf("Insira a identificacao de %i: ", i);
        scanf("%i", &identificacao);
        
        printf("Insira o peso de %i: ", i);
        scanf("%f", &peso);
        
        if (peso > maiorPeso) {
            maiorId = identificacao;
            maiorPeso =  peso;
        }
       
        if (peso < menorPeso) {
            menorId = identificacao;
            menorPeso =  peso;
        }  
    } while (i < NUMBOIS);
	
	printf("\nO maior peso é do boi %i: %f Kg", maiorId, maiorPeso);
    printf("\nO menor peso é do boi %i: %f Kg", menorId, menorPeso);
}

