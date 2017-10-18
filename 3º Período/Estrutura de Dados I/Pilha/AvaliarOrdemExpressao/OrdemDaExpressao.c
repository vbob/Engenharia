/**************************************************************************
 * Programa prioridadeexpressao.c	                                      
*
 *                                                                        
*
 * Verificando a corretude na prioridade das expressões com pilha		  
*
 * Autor: João Paulo D. Preti                                             
*
 
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/OrdemExpressao.h"

int main() {
	char expressao[] = "41 . 30 : {23 . [52 – 23 . (4 - 3) - (3 ) . 5)]} : 5";

	int resultado = avaliarAberturaEncerramento(expressao, "{[(","}])");

	if (resultado>=0) {
		printf("Expressão Inválida!\n");
		printf("%s\n",expressao);
		printf("%s\n",preencherEspacosAntes(resultado, '^'));
	}
	else
		printf("Expressão Válida!\n");


	return EXIT_SUCCESS;
}
