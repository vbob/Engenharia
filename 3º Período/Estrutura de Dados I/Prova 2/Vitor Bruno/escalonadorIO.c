// escalonadorIO do Aluno Vitor Bruno de Oliveira Barth

#include "iQueue.h"
#include <stdlib.h>
#include <string.h>

void processar(iQueue *process, iQueue *processID, iQueue *prioridade);
void desenfileirar(iQueue *process, iQueue *processID, iQueue *prioridade);
int main() {
	
	char Iprocess[100];
	strcpy(Iprocess, "10,115,20;8,15,5,10,5;40");

	iQueue processID, process, prioridade;
	
	init(&processID, 0);
	init(&process, 0);	
	init(&prioridade, 0);	

	char *buffer[100];
	char *buffer2[100];

	int i = 0;
	int j = 0;

	buffer[0] = strtok(Iprocess, ";");
	
	while(buffer[i] != NULL) {
		i++; 
		buffer[i] = strtok(NULL, ";");
	} 

	for (int i = 0; buffer[i]; i++) {
		j = 0;
		buffer2[0] = strtok(buffer[i], ",");
		
		while(buffer2[j] != NULL) {
			j++;
			buffer2[j] = strtok(NULL, ",");
			enqueue(&processID, i);
		} 

				
		for (int i = 0; buffer2[i]; i++) {
			enqueue(&process, atoi(buffer2[i]));
			if (i%2!=0)
				enqueue(&prioridade, 1);
			else
				enqueue(&prioridade, 0);
		}
	}

	// ATÉ AQUI FOI TRABALHADO SOMENTE STRING
	// A CADA PONTO E VIRGULA CRIOU-SE UMA ID DE PROCESSO NOVO
	// E A CADA VIRGULA FOI ENFILEIRADO UM PROCESSO
	// E SE A POSIÇÃO DO PROCESSO FOI PAR, É APENAS UMA ESPERA	

	// PRIORIDADES
	// 0 -> NORMAL 1 -> ESPERA

	processar(&process, &processID, &prioridade);
	
	return 0;
}

void processar(iQueue *process, iQueue *processID, iQueue *prioridade) {
	int processoAtual, prioridadeAtual, IDAtual, nProcessosEspera;
	processoAtual = prioridadeAtual = IDAtual = nProcessosEspera = 0;

	iQueue filaEspera, IDEspera;
	init(&filaEspera, 0);
	init(&IDEspera, 0);

	int IDs[10];

	while(!isEmpty(process) || processoAtual > 0 || !isEmpty(&filaEspera)) {
		if (processoAtual <= 0 && (!isEmpty(process))) {
			processoAtual = dequeue(process);
			prioridadeAtual = dequeue(prioridade);
			IDAtual = dequeue(processID);
		}

		if (prioridadeAtual == 1) {
			int bandeira = 0;

			for (int i = 0; i < nProcessosEspera; i++)
				if (IDs[i] == IDAtual)
					bandeira = 1;
			
			if (bandeira == 0) {
				enqueue(&filaEspera, processoAtual);
				enqueue(&IDEspera, IDAtual);
				IDs[nProcessosEspera] = IDAtual;
				nProcessosEspera++;
				if (!isEmpty(process)) {
					processoAtual = 0;
					prioridadeAtual = 0;
					IDAtual = 0;
				}
			}
		}

		if (nProcessosEspera > 0) {
			for (int i = 0; i < nProcessosEspera; i++) {
				enqueue(&filaEspera, (dequeue(&filaEspera)-1));
				enqueue(&IDEspera, (dequeue(&IDEspera)));
				if(peek(&filaEspera) <= 0) {
					dequeue(&filaEspera);					
					for (int i = 0; i < nProcessosEspera; i++) {
						if(IDs[i] == peek(&IDEspera))
							IDs[i] = -1;
					}
					dequeue(&IDEspera);
					nProcessosEspera--;
				}
				
				if (!isEmpty(&filaEspera))
					printf("ID = %d / Espera Restante = %d ciclos\n", peek(&IDEspera), peek(&filaEspera));
			}
		}
		
		if(processoAtual>0) {
			int bandeira = 0;

			for (int i = 0; i < nProcessosEspera; i++) {
				if (IDs[i] == IDAtual)
					bandeira = 1;
			}
			
			if (bandeira != 1) {
				processoAtual--;
				printf("ID = %d / Prioridade = %d / Restante = %d ciclos\n\n", IDAtual, prioridadeAtual, processoAtual);
			}
		
			else { 
				enqueue(process, processoAtual);
				enqueue(processID, IDAtual);
				enqueue(prioridade, prioridadeAtual);
				processoAtual = -1;
				prioridadeAtual = -1;
				IDAtual = -1;
			}
		}	
	}
}


