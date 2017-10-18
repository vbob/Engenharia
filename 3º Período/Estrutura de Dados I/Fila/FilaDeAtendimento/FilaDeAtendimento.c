#include "../Bibliotecas/iQueue.h"
#include <stdlib.h>
#define CAIXAS 2
#define TEMPOMIN 1000

void initZero(int vetor[]) {
	for (int i = 0; i < CAIXAS; i++)
		vetor[i] = 0;
}

int caixaLivre(int caixas[]) {
	for (int i = 0; i < CAIXAS; i++)
		if (caixas[i]==0)
			return i;
	return -1;
}

int main() {
	int caixas[CAIXAS], tempoCaixas[CAIXAS], tempoUltimoCliente[CAIXAS];
	initZero(caixas);
	initZero(tempoCaixas);
	initZero(tempoUltimoCliente);
	iQueue fila;
	init(&fila, 0);

	int tempoMedioEspera, tempoMaximoEspera;

	int cliente=0;
	int tempoFila = 0;

	while (!isEmpty(&fila) || tempoFila < TEMPOMIN) {
		int caixa = caixaLivre(caixas);
		if (caixa >= 0 && !isEmpty(&fila)) {
			printf("Cliente %d (tempo de espera %d) vá para o Caixa %d - TEMPO %d\n",++cliente,tempoFila-tempoUltimoCliente[caixa],caixa+1, peek(&fila));
			int tempoCliente = dequeue(&fila);
			if (tempoMaximoEspera < tempoFila-tempoUltimoCliente[caixa])
				tempoMaximoEspera = tempoFila-tempoUltimoCliente[caixa];
			tempoMedioEspera += tempoFila-tempoUltimoCliente[caixa];
			caixas[caixa]= tempoCliente;
			tempoCaixas[caixa] += tempoCliente;
			tempoUltimoCliente[caixa] = tempoFila;
		}
		
		for (int i = 0; i < CAIXAS; i++)
			if (caixas[i]!=0)
				caixas[i]--;
				
		if (tempoFila%3 == 0 && TEMPOMIN > tempoFila)
			enqueue(&fila, (int) rand() % 40);
			
		tempoFila++;
	}

	printf("\n");

	for (int i = 0; i < CAIXAS; i++)
		printf("Tempo do caixa %d: %d\n",i+1,tempoCaixas[i]);
		
	printf("\nTempo Medio de Espera: %d\n", (int) tempoMedioEspera/(cliente+1));
	printf("\nTempo Maximo de Espera: %d\n", tempoMaximoEspera);

	return 0;
}
