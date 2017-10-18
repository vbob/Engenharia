#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// METODO DE NEWTON - RHAPSON

float F(float x){
	return  2*(pow(x,3))-11.7*pow(x,2)+17.7*x-5;	// Funcao(x)
}

float derivada(float x){	// Derivada da Funcao(x)
	return 6*(pow(x,2))-23.14*x+17.7;
}

char continuar = 's';

int main(){
	float erro , valorinicial , *iteracoes; // *iteracoes = vetor iteracoes
	int iteracaoatual , numeroiteracoes = 100;
	
	printf("METODO DE NEWTON - RHAPSON PARA O ZERO DA FUNCAO F(x). \n\n");
	printf("F(x) = e^(-x) - x\n\n");
	printf("\nDigite o erro maximo: ");
	scanf("%f",&erro);
	
	while(continuar == 's'){		
	printf("\n");	
	printf("\nDigite o valor inicial: ");
	scanf("%f",&valorinicial);
	system("clear || cls");
	printf("METODO DE NEWTON - RHAPSON PARA O ZERO DA FUNCAO F(x). \n\n");
	printf("F(x) = e^(-x) - x\n\n");
	
	iteracoes = (float*) malloc(sizeof(float) * numeroiteracoes ); //Aloca��o dinamica da memoria para o vetor de iteracoes
	
	//Condicoes Inicias
	
	iteracoes[0] = valorinicial;
	iteracaoatual = 0;
	
	// Iteracoes respectivas
	printf("\n\n");
	printf("-------------------------");	
	printf("\n|%-5s|\t%-10s|\n","iter","valor de x ");
	printf("-------------------------");
	printf(" \n|%-5d|\tx = %.10f|\n",iteracaoatual,iteracoes[iteracaoatual]);
		printf("-------------------------");
	while(fabs(F(iteracoes[iteracaoatual])) > erro) {
		if(iteracaoatual > numeroiteracoes){
			printf("Nao convergiu em %d iteracoes!!! ",numeroiteracoes);
			printf("Consulte se f'(x) esta correta ");
		}
		
		iteracoes[iteracaoatual + 1] = iteracoes[iteracaoatual] - F(iteracoes[iteracaoatual]) / derivada(iteracoes[iteracaoatual]);
		iteracaoatual++;
		printf(" \n|%-5d|\tx = %.10f|\n",iteracaoatual,iteracoes[iteracaoatual]);
		printf("-------------------------");
	  }
	
	}
	free(iteracoes);
}
