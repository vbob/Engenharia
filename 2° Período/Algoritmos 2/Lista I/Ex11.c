/*	Através do método de aproximações sucessivas, chamado Método Babilônico
	Pede-se o numero do qual quer se extrair a raíz, uma aproximação (que pode ser qualquer número aleatório), e o erro
	Sendo S o numero de que ser quer extrair a raiz e x a aproximação, usa-se a formula ½(x+S/x), e verifica-se elevando a resposta ao quadrado. 
    Caso o erro seja maior que o estipulado, usa-se o valor obtido como uma nova aproximação  	*/

#include <stdio.h> 
#include <math.h>

int main() {
	float raiz, aproximacao, erro;
	printf("Insira o numero do qual se quer tirar a raiz quadrada: ");
    scanf("%f", &raiz);
    printf("Insira uma aproximacao: ");
    scanf("%f", &aproximacao);
    printf("Insira o erro: ");
    scanf("%f", &erro);
	while (abs((aproximacao*aproximacao)-raiz) > erro) {
		aproximacao = ((aproximacao+(raiz/aproximacao))/2);
     }
	printf("\nA raiz quadrada aproximada de %f e %f", raiz, aproximacao);
}
