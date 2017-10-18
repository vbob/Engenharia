#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Para executar o método serão passadas as seguintes informações:
// O limite inferior (lInferior) e limite superior (lSuperior)
// A tolerância (ou seja, o erro aceitável) e o número maximo de iterações (iMaximo) 
// e a iteração atual (iAtual) 
// o iAtual inicialmente começa em ZERO

void metodo(float lInferior, float lSuperior, float erroAceitavel, int iMaximo, int iAtual);
float funcao(float x);

int main() {
	system("cls");	
	printf("Determinar raiz da seguinte equacao: (100*exp(-0.005*x)*cos(sqrt(2000-(pow(x,2)/100))*0.05)-1)\n \n");
	printf("|\tIteracao\t|\tlimite Inferior\t|\tlimite Superior\t|\tErro\t\t|\tAproximacao\t|\tf(Aproximacao)\t|\n");
	printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
	metodo(330, 335, 0.00001, 100, 0);

	printf("|\tIteracao\t|\tlimite Inferior\t|\tlimite Superior\t|\tErro\t\t|\tAproximacao\t|\tf(Aproximacao)\t|\n");
	printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
	metodo(-400, -300, 0.0001, 100, 0);
}

void metodo(float lInferior, float lSuperior, float erroAceitavel, int iMaximo, int iAtual) {
	float aproximacao = ((lInferior+lSuperior)/2);
	float erroAtual = (fabs(funcao(aproximacao)));

	printf("|\t%i\t\t|\t%f\t|\t%f\t|\t%f\t|\t%f\t|\t%f\t|\n", iAtual, lInferior, lSuperior, erroAtual, aproximacao, funcao(aproximacao));
	
	// Qual limite (superior ou inferior) o aproximacao substituirá
	if (funcao(lInferior)*funcao(lSuperior) < 0){
		if (funcao(lInferior)*funcao(aproximacao) < 0)
			lSuperior = aproximacao;
		else if (funcao(lSuperior)*funcao(aproximacao) < 0)
		lInferior = aproximacao;
	}else{
		if (funcao(lSuperior)*funcao(lInferior) > 0){
			printf("\n\nO metodo falhou: Nao ha raiz nesse intervalo");
			return;
		}else{
			printf("\n\nO metodo falhou: A funcao nao e continua em um dos intervalos\n");
			return;
		}
	}	
		
	// Condição de Parada ou Continuação
	if (erroAtual <= erroAceitavel)
		printf("\n\nA funcao possui uma raiz em aproximadamente %f \n\n", aproximacao);
	else if (iAtual >= iMaximo)
		printf("\n\nO método falhou: Em %d iteracoes o erro e maior que %f\n\n", iAtual, erroAceitavel);
	else 
		metodo(lInferior, lSuperior, erroAceitavel, iMaximo, iAtual+1);		
}

// E temos a subrotina abaixo onde será colocada a função qual se quer achar o zero
float funcao(float x) {
	return (100*exp(-0.005*x)*cos(sqrt(2000-(pow(x,2)/100))*0.05)-1);
}
