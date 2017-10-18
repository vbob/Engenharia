/*
 * provaMain.c
 *
 *  Created on: 29 de nov de 2016
 *      Author: joaopaulodelgadopreti
 */

#include "provaWords.h"

int main() {

	wordList words;
	init(&words);

	//Deverá imprimir o índice apenas de A a Z.
	//Serve para verificar se o init foi executado corretamente.
	for (No *aux = words.firstChar; aux!=NULL;aux=aux->nextWord) {
		printf("%c\n",aux->character);
	}

	add(&words,"AZEITONA\0");
	add(&words,"AZEITEI\0");
	add(&words,"AZEDO\0");
	add(&words,"ABACATE\0");
	add(&words,"ABACATEIRO\0");
	add(&words,"ABACAXI\0");

	//As próximas instruções tem por finalidade verificar se o add foi executado corretamente.
	//Deverá imprimir a primeira palavra adicionada (AZEITONA)
	for (No *aux = words.firstChar->nextChar; aux!=NULL; aux=aux->nextChar) {
		printf("%c -> ",aux->character);
	}
	printf("\n");

	//Deverá imprimir AZEITE
	printf("%c -> ",words.firstChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextChar->nextChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextChar->nextChar->nextChar->nextChar->nextWord->character);

	//Deverá imprimir ABACATE
	printf("\n");
	printf("%c -> ",words.firstChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->nextChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->nextChar->nextChar->nextChar->nextChar->character);
	printf("%c -> ",words.firstChar->nextChar->nextWord->nextChar->nextChar->nextChar->nextChar->nextChar->character);

	//Verificar se o comando getWordsQtty está funcionando
	//Deverá imprimir 6 (que é a quantidade de palavras que começam com A)
	printf("\n\nQtde: %d\n",getWordsQtty(words.firstChar));

	//Verificar se o comando show está funcionando
	//Deverá imprimir todas as palavras cadastradas que começam com A
	char buffer[30];
	show(words.firstChar->nextChar, buffer, 0);

	return EXIT_SUCCESS;
}

