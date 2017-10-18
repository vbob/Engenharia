#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/iStack.h"

int desempilha(char operacao[3], iStack *pilha);
void AdicionaValor(char valor[3], iStack *pilha);
void adicionaExpressao(char *sentence, iStack *pilha);

int main() {
	iStack pilha;
	init(&pilha, 1);
	
	printf("INICIO CALCULADORA\n");

	char expressao[50] = "2 50 30 + / 10 -";
	
	adicionaExpressao(expressao, &pilha);
	
	printf("RESULTADO = %i \nFIM CALCULADORA\n", pop(&pilha));

	return EXIT_SUCCESS;	
}

void AdicionaValor(char valor[3], iStack *pilha) {
	if((in(valor[0], " + / - * / ") <= 0))
		push(pilha, atoi(valor));
	else
		push(pilha, desempilha(valor, pilha));
}

int desempilha(char *operacao, iStack *pilha) {
	if(operacao[0] == '-')
		return pop(pilha) - pop(pilha);	

	if(strcmp(operacao, "+") == 0)
		return pop(pilha) + pop(pilha);	

	if(strcmp(operacao, "*") == 0)
		return pop(pilha) * pop(pilha);	

	if(operacao[0] == '/')
		return pop(pilha) / pop(pilha);	

	printf("ERRO NA OPERACAO");
	return -1;
}

void adicionaExpressao(char *sentence, iStack *pilha) {
	char *vAtual = strtok(sentence, " ");	
		
	while(vAtual != NULL) {
		AdicionaValor(vAtual, pilha);
		vAtual = strtok(NULL, " ");	
	}
}

