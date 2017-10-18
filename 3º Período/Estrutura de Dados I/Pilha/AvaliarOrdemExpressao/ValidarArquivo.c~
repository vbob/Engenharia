/* VALIDAR ARQUIVO */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/OrdemExpressao.h"

int main() {
	char uma_linha[1000];
	char *c;
		
	char arquivo[10000];	

	FILE *ARQUIVO;
	ARQUIVO = fopen("teste.c","r");

	int pArquivo = 0;
	
	do {
		c = fgets(uma_linha,100,ARQUIVO);
		if (c != NULL) {
			for(int i = 0; uma_linha[i]; i++) {
				arquivo[pArquivo] = uma_linha[i];
				pArquivo++;
			}
		}
	} while (c != NULL);
	
	int resultado = avaliarAberturaEncerramento(arquivo, "{[(","}])");
	int linhaErro = 1;
	for (int i = 0; i <= resultado; i++) {
		if (arquivo[i] == '\n')
			linhaErro++;
	}

	if (resultado>=0) {
		printf("\nExpressão Inválida!\n");
		printf("Erro na linha %i", linhaErro);
	}
	else
		printf("Expressão Válida!\n");

	fclose(ARQUIVO);

	return EXIT_SUCCESS;
}
