/* Esse algoritmo lê Altura, Sexo de um grupo de 50 pessoas fornece como resultado: 
		   - Maior e menor altura
		   - Menor altura de mulheres
		   - O número de homens */

#include <stdio.h>
#define QUANTIDADE 50

int main() {
	// Declaração de variáveis

	float menor, media, maior, mulheres, i, altura;
	char sexo;
	
	// Leitura da primeira pessoa
	printf("Entre com o valor da altura em cm ");
	scanf("%d", &altura);
	printf("\nEntre com o valor do sexo (m e f) ");
	scanf("%s", &sexo);
	
	// Inicialização das variáveis
	menor = altura;
	maior = altura;
	media = 0;
	mulheres = 0;
	
	if (sexo == 'f' || sexo == 'F') {
		mulheres = 1;
		media = altura;
	}
	
	if  (altura < menor) {
			menor = altura;
		}
		
		if (altura > maior) {
			maior = altura;
	}
		
	// Laço de repetição para acumular as alturas lidas, o número de homens e determinar a maior e menor alturas
	for (i = 1; i < QUANTIDADE; i++) {
		printf("\nEntre com o valor da altura em cm ");
		scanf("%i", &altura);
		printf("\nEntre com o valor do sexo (m e f) ");
		scanf("%s", &sexo);
		
		// Determinar maior e menor
		if  (altura < menor) {
			menor = altura;
		}
		
		if (altura > maior) {
			maior = altura;
		}
		
		
		// Acumular quantidade de homens e alturas lidas
		if (sexo == 'f' || sexo == 'F') {
			mulheres += 1;
			media = altura;
		}
	}
	// Imprima o resultados
	
	
	printf("\n O menor valor é %f \n O maior valor é %f \n A media da altura das mulheres é %f \n A quantidade de homens é %f", menor, maior, media/mulheres, mulheres);	
	
	return 0;
}		 