#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// METODO DE NEWTON - RHAPSON

float F(float x){
	return  exp(-x) - x;	// Funcao(x)
}

float derivada(float x){	// Derivada da Funcao(x)
	return - exp(-x) - 1;
}

char continuar = 's';

int main(){
	float erro , valorinicial , *iteracoes, erroAtual; // *iteracoes = vetor iteracoes
	int iteracaoatual , numeroiteracoes = 100;
	
	printf("METODO DE NEWTON - RHAPSON PARA O ZERO DA FUNCAO F(x). \n\n");
	printf("F(x) = e^(-x) - x\n\n");
	printf("\nDigite o erro: ");
	scanf("%f",&erro);
	
	while(continuar == 's'){		
	printf("\n");	
	printf("\nDigite o valor inicial: ");
	scanf("%f",&valorinicial);
	system("clear || cls");
	printf("METODO DE NEWTON - RHAPSON PARA O ZERO DA FUNCAO F(x). \n\n");
	printf("F(x) = e^(-x) - x\n\n");
	
	iteracoes = (float*) malloc(sizeof(float) * numeroiteracoes ); //Alocação dinamica da memoria para o vetor de iteracoes
	
	//Condicoes Inicias
	
	iteracoes[0] = valorinicial;
	iteracaoatual = 0;
	erroAtual = fabs((iteracoes[iteracaoatual + 1] - iteracoes[iteracaoatual]) / iteracoes[iteracaoatual + 1])*100;
	
	// Iteracoes respectivas
	printf("\n\n");
	printf("_______________________________________");	
	printf("\n|%-5s|\t%-10s\t|%-10s|\n","iter","valor de x ", "Erro Aproximado");
	printf("_______________________________________");
	printf(" \n|%-5d|\tx = %.10f|  %-10f|\n",iteracaoatual,iteracoes[iteracaoatual], erroAtual);
	printf("_______________________________________");
		
	while(fabs(F(iteracoes[iteracaoatual])) > erro){
			
		if(iteracaoatual > numeroiteracoes){
			printf("Nao convergiu em %d iteracoes!!! ", numeroiteracoes);
			printf("Consulte se f'(x) esta correta ");
		}
		
		iteracoes[iteracaoatual + 1] = iteracoes[iteracaoatual] - F(iteracoes[iteracaoatual]) / derivada(iteracoes[iteracaoatual]);
		
		erroAtual = (fabs((iteracoes[iteracaoatual + 1] - iteracoes[iteracaoatual]) / iteracoes[iteracaoatual + 1])*100);  //Ea = |(Xi+1 - Xi)/Xi+1| *100
		
		iteracaoatual++;
		
		
		printf(" \n|%-5d|\tx = %.10f|  %-10f|\n", iteracaoatual, iteracoes[iteracaoatual], erroAtual);
		printf("_______________________________________");
	  }
	
	}
	free(iteracoes);
}
