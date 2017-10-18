#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *ARQUIVO;
	char linha[255];
	int i;
	ARQUIVO = fopen("arquivo-texto.txt", "w");
	if (ARQUIVO== NULL) {
	 	char selecao[2];
		do {	
			system("clear");
			printf("\nArquivo corrompido");
			printf("\nDeseja apagar o arquivo atual? (S/N): ");
			scanf(" %s", selecao);
			switch (selecao[0]) {
				case 's': system("rm arquivo-texto.txt");
					  break;             
				case 'S': system("rm arquivo-texto.txt");
				   	  break;
				case 'n': break;          
				case 'N': break;
				default: break;      
			} 
		} while ((selecao[0] =! 'n') || (selecao[0] != 's'));
	}
	strcpy(linha,"Esta é uma linha de exemplo.");
	for (i = 0; i <= 10; i++) 
		fprintf(ARQUIVO, "%s Numero de linhas %d\n", linha, i);
	fclose(ARQUIVO);
}
	
