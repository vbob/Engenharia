#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/sStack.h"

int main() {
	sStack pilha;
	init(&pilha, 1);
	
	printf("INICIO CALCULADORA\n");

	char expressao[50] = "(50 + 30)/2 - 10";

	printf("RESULTADO = %s \nFIM CALCULADORA\n", pop(&pilha));

	return EXIT_SUCCESS;	
}

