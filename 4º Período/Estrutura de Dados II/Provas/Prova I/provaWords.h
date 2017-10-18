/*
 * provaWords.h
 *
 *  Created on: 29 de nov de 2016
 *      Author: joaopaulodelgadopreti
 *
 *  Biblioteca responsável por armazenar palavras (string) de forma a otimizar o uso
 *  de caracteres que se repetem para formar novas palavras.
 *
 *  Exemplo (armazenar as palavras AZEITONA, AZEITE, AZEDO, ABACATE, ABACATEIRO, ABACAXI):
 *
 * A -> Z -> E -> I -> T -> O -> N -> A
 * 					     -> E
 * 			   -> D -> O
 * A -> B -> A -> C -> A -> T -> E -> I -> R -> O
 * 			             -> X -> I
 *
 *  Normalmente seriam necessários 43 caracteres, com o uso da biblioteca,
 *  apenas 23 caracteres são necessários.
 */

/*
 * ALUNO: Vitor Bruno de Oliveira Barth
 */

#ifndef PROVAWORDS_H_
#define PROVAWORDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 30	//Máximo para o tamanho da palavra
#define A 		  65	//codigo ASCII da letra A
#define Z 		  90	//codigo ASCII da letra Z

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;

typedef struct No {
	struct No *nextChar; //Próxima letra da palavra
	struct No *nextWord; //Começa uma nova palavra
    char   character;	 //caractere da palavra
    bool   word;		 //valor lógico que indica que nesse no já se forma uma palavra
}No;

typedef struct wordList {
    No *firstChar;
    int size; 			//Qtde de Palavras já cadastradas
}wordList;

/*
 *  Objetivo: Inicializar a lista de palavras criando todos os No das letras A..Z
 *
 *  É criado um No para cada letra de A..Z (ASCII 65 até 90) onde firstChar aponta para
 *  o No A e o nextWord de cada letra aponta para o seu sucessor no alfabeto.
 *
 *  Pontos: 2,0
 */
void  init			(wordList *words);

/*
 *  Objetivo: Adicionar a palavra à lista de palavras
 *
 *  Procura na lista o No que corresponde ao primeiro caractere da palavra.
 *  O primeiro No não deve ser utilizado para compor a palavra, é apenas um índice
 *  para localizar palavras que começam com aquela letra, ou seja, ABACATE, fisicamente
 *  vai estar como AABACATE.

 *
 *  Pontos: 3,0
 */
int   add			(wordList *words, char word[WORD_SIZE]);

/*
 *  Objetivo: Exibir todas as palavras a partir do No informado
 *
 *  Por exemplo, se passar words.firstChar->nextChar deverá apresentar todas as palavras
 *  que começam com a letra A.
 *
 *  Um buffer é necessário para guardar o que deve ser impresso em uma nova linha quando
 *  uma nova palavra aparecer.
 *
 *  O parâmetro i serve para indicar em que posição do buffer deve ser guardado o novo
 *  caractere.
 *
 *  Pontos: 2,5
 */
void  show			(No *no, char buffer[WORD_SIZE], int i);

/*
 *  Objetivo: Retornar a quantidade de palavras cadastradas a partir do No informado
 *
 *  Pontos: 2,5
 */
int   getWordsQtty  (No *start);

void init 			(wordList *words) {
	No *anterior = (No*) malloc(sizeof(No));
	anterior->character = A;
	anterior->word = false;
	words->firstChar = anterior;
	
	for (int i = A+1; i <= Z; i++) {
		No *cache = (No*) malloc(sizeof(No));
		cache->character = i;
		cache->word = false;
		anterior->nextWord = cache;
		anterior = cache;
	}

	words->size = 0;
}

int   add			(wordList *words, char word[WORD_SIZE]) {
	No *letraAnterior = words->firstChar;
	for (; letraAnterior->character != word[0]; letraAnterior=letraAnterior->nextWord);
	int posicaoInicial = 0;

	while (letraAnterior->nextChar) {
		if (letraAnterior->nextChar->character == word[posicaoInicial]) {
			posicaoInicial++;
			letraAnterior=letraAnterior->nextChar;
		}
		else break;
	}

	if (letraAnterior->nextWord) {
		if (letraAnterior->nextWord->character == word[posicaoInicial]) {
			letraAnterior=letraAnterior->nextWord;
			while (letraAnterior->nextChar && letraAnterior->nextChar->character == word[posicaoInicial+1]) {
				posicaoInicial++;
				letraAnterior=letraAnterior->nextChar;
			}
		}
	}

	for (int i = posicaoInicial; word[i]; i++) {
		No* cache = (No*) malloc(sizeof(No));
		cache->character = word[i];
		cache->word = false;
		if (letraAnterior->nextChar) {
			if (word[i+1]) {
				if (letraAnterior->nextChar->character != word[i+1])
				letraAnterior->nextWord = cache;
			}
		}
		else
			letraAnterior->nextChar = cache;
		letraAnterior = cache;
	}
	letraAnterior->word = true;
	return 0;
}

void  show			(No *no, char buffer[WORD_SIZE], int i) {
	No * aux = no;
	buffer[0] = ' ';
	for (i=i+1; aux; aux=aux->nextChar, i++) {
		buffer[i] = aux->character;
		if (aux->nextWord) {
			show(aux->nextWord, buffer, i);
		}
	}
	printf("%s\n", buffer);
}

int   getWordsQtty  (No *start) {
	int count = 1; // Começa em 1 pq eu já estou eu julgo que já estou em uma palavra
	No * aux;
	for (aux = start; aux->nextChar; aux=aux->nextChar) {
		if (aux->nextWord)
			count += getWordsQtty(aux->nextWord);
	}
	return count;
}

#endif /* PROVAWORDS_H_ */
