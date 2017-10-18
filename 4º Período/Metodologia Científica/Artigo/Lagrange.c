#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

/* Polinomio de Lagrange */

int main() {
	int n, i, j, y=0;
	float x[MAX], f[MAX], ponto, Ln, Pn = 0;
	
	printf("\nEntre com o grau: ");	//usuário entra com o grau
	scanf("%d", &n); //leitura do grau
	
	for(i=0; i<=n; i++){ //leitura dos X e Y
		printf("\nEntre com o valor de x(%d) e f(x%d): ", i, i);
		scanf("%f %f", &x[i], &f[i]);
	}

	printf("\n");
	printf("\n________________________________________________________________________________________");
	
	for(i=0; i<=n; i++){
		printf("\nx(%d) = %f \t\t f(x%d) = %f", i, x[i], i, f[i]); // Imprime os valores que o usuário entrou
	}
	
	printf("\n________________________________________________________________________________________");
	
	
	do{
		printf("\n\n\nEntre com o ponto para se obter a estimativa: "); //usuário entra com o ponto
		scanf("%f", &ponto);
		
		for(j=0; j<=n; j++){
			Ln = 1; // Inicializa o L com 1 para calcular o próximo Ln
			for(i=0; i<=n; i++){
				if(i!=j){ /*i nao pode ser igual a j pq o valor do xn no cálculo do Ln nao pode estar no numerador,
							exemplo: Ao calcular o L0 (grau 1) = (x - x1) / (x0 - x1)
							observe que o x0 está no denominador */
							
					Ln = Ln * ((ponto - x[i]) / (x[j] - x[i])); /*valor de Ln, se o grau for maior do que 1 L vai 
																receber n vezes a multiplicaçao dos pontos. 
																Exemplo: Para n=2
																L = ((x - x1)(x - x2)) / ((x0 - x1)(x0 - x2)
																Assim sucessivamente...    */
				}
			}
		Pn = (Ln * f[j]) + Pn; //O polinomio será o somatório de f(xn) * Ln(x)
		}
	
		printf("\n________________________________________________________________________________________");
		printf("\n\nO valor estimado de f(%f) e': %f", ponto, Pn); //Imprime o valor estimado do ponto que o usuário forneceu
	
		printf("\n\n\n0: Testar outro ponto "); // caso o usuário queira testar outro ponto
		printf("\n1: Encerrar \n");
		scanf("%d", &y);
	
	}while (y==0);
	

	return 0;
}
