/* Biblioteca PRIORIDADE_DA_EXPRESSAO */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cStack.h"

int in(char elemento, char elementos[]) {
	for (int i = 0; elementos[i]!=0; i++)
		if (elemento == elementos[i])
			return i;
	return -1;
}

int avaliarAberturaEncerramento(char expressao[], char charsAbertura[], char charsEncerramento[]) {
	cStack pilha;
	init(&pilha,1);

	for (int i = 0 ; expressao[i] != 0 ; i++) {
		if (in(expressao[i],charsAbertura)>=0)
			push(&pilha,expressao[i]);

		if (in(expressao[i],charsEncerramento)>=0) {
			if (!isEmpty(&pilha)) {
				if (in(pop(&pilha),charsAbertura) == in(expressao[i],charsEncerramento)) {
					//Não faz nada. O pop ja foi executado.
				} else {
					return i;
				}
			} else {
				return i;
			}
		}
	}
	return -1;

}

char* preencherEspacosAntes(int qtdeEspacos, char c) {
	char *texto = (char *) malloc(sizeof(char) * qtdeEspacos);
	for (int i = 0 ; i < qtdeEspacos ; i++)
		texto[i] = ' ';
	texto[qtdeEspacos-2] = c;
	texto[qtdeEspacos-1] = '\0';
	return texto;
}
