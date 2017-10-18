/*           Ler a idade de individuos até digitar 0 
	    	 Escrever a idade media do grupo 			*/
             
#include <stdio.h>

int main() {
	int idade, i;
    float mediaidade;
	// Ler o primeiro
    printf("Insira a idade de 1: ");
    scanf("%i", &idade);
	mediaidade = 0;
	i = 0;

	// Loop de leitura 
	while (idade != 0) {		
        mediaidade = mediaidade + idade;
        i++;
        printf("Insira a idade de %i: ", i);
        scanf("%i", &idade);
    }
    
    mediaidade = mediaidade/i;
	printf("\nA média das idades é %f", mediaidade);
    
    return 0;
}


