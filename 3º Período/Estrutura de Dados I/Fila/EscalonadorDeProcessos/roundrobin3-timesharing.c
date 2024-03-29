#include "../Bibliotecas/iQueue.h"
#include <stdlib.h>

#define NUCLEOS 4

typedef struct {
	int processoAtual;
	int tempoOcioso;
	int timeShare;
	iQueue processos;	
} CPU;

void executarTarefas(CPU *cpu, iQueue *processos);
int podeSair(CPU *cpu, iQueue *processos, int tempo);
void melhorProcessador(int processo, CPU *cpu); 
int tempoFila(iQueue *fila); 

int main() {
	CPU cpu[NUCLEOS];
	
	for (int i = 1; i <= NUCLEOS; i++)
		cpu[i-1].timeShare = 50*i;

	iQueue processos;
	init(&processos);
	enqueue(&processos, 111);
	enqueue(&processos, 222);
	enqueue(&processos, 428);
	enqueue(&processos, 303);
	enqueue(&processos, 282);
	enqueue(&processos, 586);
	enqueue(&processos, 294);
	enqueue(&processos, 513);
	enqueue(&processos, 771);
	enqueue(&processos, 248);
	enqueue(&processos, 691);
	enqueue(&processos, 523);

	executarTarefas(cpu, &processos);
}

void executarTarefas(CPU *cpu, iQueue *processos) {
	int t = 0;
	while (!isEmpty(processos))
		melhorProcessador(dequeue(processos), cpu);

	/*for(int tempo = 0; podeSair(cpu, processos, tempo); tempo++) {
		for (int i = 0; i < NUCLEOS; i++) {
			cpu[i].processoAtual--;
			
		}				
	}*/

	for (int i = 0; i < NUCLEOS; i++) {
		printf("\nCPU %d", i);
		show(&cpu[i].processos);
	}
}

int podeSair(CPU *cpu, iQueue *processos, int tempo) {
	if(tempo%cpu[NUCLEOS-1].timeShare==0) {
		if(isEmpty(processos))
			return 1; 
	}

	return 0;	
}

void melhorProcessador(int processo, CPU *cpu) {
	int melhorProcessador;
	int menorOcioso = cpu[NUCLEOS].timeShare;
	int maiorFila = 0;

	/*for (int i = 0; i < NUCLEOS; i++) {
		if (tempoFila(&cpu[i].processos) > maiorFila)
			maiorFila = tempoFila(&cpu[i].processos);
	} */
	
	for (int i = 0; i < NUCLEOS; i++) {
		if (i%cpu[i].timeShare < menorOcioso /*&& tempoFila(&cpu[i].processos) < maiorFila*/) {
			menorOcioso = i%cpu[i].timeShare;
			melhorProcessador = i;
		}
	} 
	
	enqueue(&cpu[melhorProcessador].processos, processo);
}

int tempoFila(iQueue *fila) {
	int tempo = 0;
	for(int i = 0; i < size(fila); i++) {
		if (!isEmpty(fila)) {
			tempo += peek(fila);
			enqueue(fila, dequeue(fila));
		}
	}
	return tempo;
}
