/* 10 conjuntos de 2 valores
Um representa o numero do aluno e outro representa a altura do aluno
Mostre o número do aluno mais alto e do mais baixo junto com a altura */

#include <stdio.h>
#define ALUNOS 10

int main() {
	// Declarar variaveis
	int num, altura, maiorNum, maiorAltura, menorNum, menorAltura, i;
	
	// Ler o primeiro aluno
	printf("Numero do aluno 1: ");
	scanf("%i", &maiorNum);
	printf("Altura do aluno 1 (em cm): ");
	scanf("%i", &maiorAltura);
	menorNum = maiorNum;
	menorAltura = maiorAltura;
	i = 2;
	
	// Loop e verificar condicoes
	do {
		printf("Numero do aluno %i: ", i);
		scanf("%i", &num);
		printf("Altura do aluno %i (em cm): ", i);
		scanf("%i", &altura);
	
		if (altura > maiorAltura) {
			maiorNum = num;
			maiorAltura = altura; 
		}
		
		if (altura < menorAltura) {
			menorNum = num;
			menorAltura = altura;
		}
		
		i++; 
	} while (i <= ALUNOS);
	
	// Imprimir os resultados
	printf("Maior aluno: Numero %i, Altura %i", maiorNum, maiorAltura);
	printf("\nMenor aluno: Numero %i, Altura %i", menorNum, menorAltura);
	
	return 0;
}