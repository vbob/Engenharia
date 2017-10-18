//compilador.c de VITOR BRUNO DE OLIVEIRA BARTH

#include <stdio.h>
#include <stdlib.h>
#include "./sStack.h"

// DECLARE SUBROUTINES
void lerArquivo(char *nomeDoArquivo, sStack *stack, char *subrotina); //Lê o arquivo todo

int main() {
	sStack pilha;
	sInit(&pilha);
	lerArquivo("program.edd", &pilha, NULL);
	sShow(&pilha);
	return -1;
}

void lerArquivo(char *nomeDoArquivo, sStack *stack, char *subrotina) {
	char uma_linha[1000];
	char *buffer;
	FILE *ARQUIVO;
	ARQUIVO = fopen(nomeDoArquivo,"r");
	int i = 0;

	char acao[100]; 
	char arg[100];

	do {
		buffer = fgets(uma_linha, 100, ARQUIVO);
		if (buffer != NULL) {			// SE BUFFER LIDO NAO É NULO
			if (strcmp(buffer, "return\n") != 0) {
				strcpy(acao, strtok(buffer, " ")); // DIVIDE NO ESPACO, PRIMEIRA PARTE É A ACAO
				strcpy(arg, strtok(NULL, " ")); // SEGUNDA PARTE É O ARGUMENTO
			} 
			
			else {
				strcpy(acao, "return");
				strcpy(arg, "0");
			}

			if (subrotina == NULL) {
				if(strcmp(acao, "print") == 0) {
					sPush(stack, arg);
				}
				else if(strcmp(acao, "return") == 0)
					break;
				else if(strcmp(acao, "call") == 0)
					lerArquivo(nomeDoArquivo, stack, arg);
			}

			else if (strcmp(acao, "routine") == 0 && strcmp(subrotina, arg) == 0)
				subrotina = NULL;
			i++;			
		}
	} while (buffer != NULL);
	fclose(ARQUIVO);
}

