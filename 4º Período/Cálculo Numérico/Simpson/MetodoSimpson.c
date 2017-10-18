#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Aplica��es M�ltiplas da Regra de 1/3 de Simpson */

void MetodoSimpson(int segmentos, float limiteSuperior, float limiteInferior);
void area(float altura, float limiteInferior, float limiteSuperior, float somaPares, float somaImpares, int segmentos);
float funcao(float x);
void erro(float limiteInferior, float limiteSuperior, int segmentos);


int main() {
	printf("\n\nAplicacoes Multiplas da Regra de 1/3 de Simpson\n");
	MetodoSimpson(4, 0.8, 0);
	return 0;
}


void MetodoSimpson(int segmentos, float limiteSuperior, float limiteInferior) {
	float somaPares, somaImpares, altura, pontoAtual;
	int i;

	if (segmentos <= 0) {
		printf("\nInv�lido"); //numero de segmentos n�o pode ser zero ou negativo
	}
		else {
			if (segmentos % 2 != 0) segmentos = segmentos + 1; // O numero de segmentos deve ser par

			altura = (limiteSuperior - limiteInferior) / segmentos; // A altura � calculada dividindo a largura pelo numero de segmentos
			pontoAtual = limiteInferior + altura; // o limite inferior e o limite superior nao sao somados na soma dos pares e dos �mpares
			somaImpares = 0; //inicializa a soma dos numeros ímpares
			somaPares = 0;  //inicializa a soma dos numeros pares

			for (i = 1; i < segmentos; i++) { //realiza a soma dos f �mpares e dos f pares, at� segmentos-1, pois o f dos extremos nao � inclu�do na soma dos pares e �mmpares
				
				if (i % 2 == 0) {  //verifica se o pontoAtual � par, para somar os pares
					somaPares = somaPares + funcao(pontoAtual);   //somat�rio dos f pares
				}
				else { // soma dos �mpares
					somaImpares = somaImpares + funcao(pontoAtual); //somat�rio dos f �mpares
				}
				pontoAtual = pontoAtual + altura; //pr�ximo ponto
			}
			
			area(altura, limiteInferior, limiteSuperior, somaPares, somaImpares, segmentos); //chama a fun�ao para calcular a integral, utilizando o m�todo de simpson
		}
}


void area(float altura, float limiteInferior, float limiteSuperior, float somaPares, float somaImpares, int segmentos) { //calculo da integral a partir do m�todo de simpson
	float resultado;

	resultado = ((altura / 3) * (funcao(limiteInferior) + funcao(limiteSuperior) + (4 * somaImpares) + 2 * somaPares)); //calculo da integral

	printf("\nA area da funcao e': %f", resultado); //imprime o resultado
	erro(limiteInferior, limiteSuperior, segmentos); //imprime o erro
}


float funcao(float x) {
	return (0.2 + (25 * x) - (200 * pow(x, 2)) + (675 * pow(x, 3)) - (900 * pow(x, 4)) + (400 * pow(x, 5))); //fun�ao para calcular a integral
}



void erro(float limiteInferior, float limiteSuperior, int segmentos) { //calculo do erro
	float erroA;

	erroA = (-(((pow((limiteSuperior - limiteInferior), 5)) / (180 * pow(segmentos, 4))) *(-2400))); //obs: -2400 � o valor m�dia da derivada 4
	printf("\nEa = %f \n\n\n\n", erroA);
} 

