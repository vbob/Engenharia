#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	system("clear");
	char uma_linha[100];
	char *c;
	FILE *ARQUIVO;
	ARQUIVO = fopen("transacoes.txt","r");
	do {
		c = fgets(uma_linha,100,ARQUIVO);
		if (c != NULL) 
			printf ("%s", uma_linha);
	} while (c != NULL);
	fclose(ARQUIVO);
} 
