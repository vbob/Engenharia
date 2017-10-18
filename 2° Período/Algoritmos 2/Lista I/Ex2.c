/* 5 conjuntos de 3 valores
Codigo da cidade, numero de veiculos de passeio, numero de acidentes com vitimas
Resulta o maior e menor indice de acidentes e as cidades
A media de veiculos nas cidades juntas
A media de acidentes nas cidades com menos de 2000 veiculos */

#include <stdio.h>
#define NUMCIDADES 5
#define COMPARADOR 2000

int main() {
	// Declarar variaveis
	int cod, numVei, numAci, maiorCod, maiorAci, menorCod, menorAci, i, j;
	float medAci, medVei;
	
	// Ler primeira cidade
	printf("Insira o código da 1a cidade: ");
	scanf("%i", &maiorCod);
	printf("Insira o numero de veiculos da 1a cidade: ");
	scanf("%i", &medVei);
	printf("Insira o numero de acidentes 1a cidade: ");
	scanf("%i", &maiorAci);
	menorCod = maiorCod;
	menorAci = maiorAci;
	i = 2;
	
	// Verificar se cidade 1 possui mais de COMPARADOR veiculos
	if (medVei > COMPARADOR) {
		medAci = medVei;
		j = 1;
	}
	
	// Loop para ler as outras cidades e verificar COMPARADOR veiculos
	do {
		// Ler i cidade
		printf("Insira o código da %ia cidade: ", i);
		scanf("%i", &cod);
		printf("Insira o numero de veiculos da %ia cidade: ", i);
		scanf("%i", &numVei);
		printf("Insira o numero de acidentes %ia cidade: ", i);
		scanf("%i", &numAci);
		i++;
		medVei += numVei;
		
		// Verificar num acidentes 
		if (numAci > maiorAci) {
			maiorAci = numAci;
			maiorCod = cod;
		}
		if (numAci < menorAci) {
			menorAci = numAci;
			menorCod = cod;
		}
		
		// Verificar se cidade 1 possui mais de COMPARADOR veiculos
		if (medVei > COMPARADOR) {
			medAci += numAci;
			j++;
		}
	} while (i <= NUMCIDADES);
	
	// Imprimir os resultados
	printf("\nMaior numero de acidentes: Código: %i, Num de Acidentes:%i", maiorCod, maiorAci);
	printf("\nMenor numero de acidentes: Código: %i, Num de Acidentes:%i", menorCod, menorAci);
	printf("\nMedia de veiculos: %f", medVei/NUMCIDADES);
	printf("\nMedia de acidentes em cidades com menos de %i veiculos: %f", COMPARADOR, medAci/j);
}