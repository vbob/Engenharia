#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIMPAR system("clear");
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar()
#define SEP ";"

typedef struct {
	char nome[30], sexo[2], cpf[13];
} CLIENTE;


void main() {
	CLIENTE cliente[20];
	FILE *arquivo;
	arquivo = fopen("clientes.csv", "r");
	if (arquivo == NULL) {
		printf("ARQUIVO INVALIDO");
		LIMPAR;
		ESPERAR;
	}
	else {
		LIMPAR;
		char linha[100], *str;	
		int i = 0;	
		str = fgets(linha, 100, arquivo);
		while (!feof(arquivo)) {
			strcpy(cliente[i].nome, strtok(str, SEP));
			strcpy(cliente[i].sexo, strtok(NULL, SEP));
			strcpy(cliente[i].cpf, strtok(NULL, SEP));
			str = fgets(linha, 100, arquivo);
			i++;
		}
		
		int tamanho = i;
		
		int naoA = 0, qpalavras[4], soConsoantes = 0;
		for (i = 0; i < 4; i++)
			qpalavras[i] = 0;
		char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
		for (i = 0; i < tamanho; i++) {
			if (tolower(cliente[i].nome[0]) != 'a' && tolower(cliente[i].sexo[0] == 'm'))
				naoA++;
		}
		int tamanhoPalavra = 0, bandeira1 = 0;
		for (i = 0; i < tamanho; i++) { // Loop dos nomes no registro
			tamanhoPalavra = 0, bandeira1 = 0;
			for (int j = 0; cliente[i].nome[j]; j++) { // Loop do tamanho do nome
				if (cliente[i].nome[j] != ' ' && cliente[i].nome[j]) {
					int bandeira2 = 0;
					for (int k = 0; k < 5; k++) { // Loop das vogais
						if (tolower(cliente[i].nome[j]) == vogais[k])
							bandeira2 = 1;
					}
					if (bandeira2 != 1)
						bandeira1 = 1;
					tamanhoPalavra++;		
				}
				
				if (cliente[i].nome[j] == ' ' || !cliente[i].nome[j+1]) {
					switch(tamanhoPalavra) {
						case 1: break;
						case 2: qpalavras[0]++;
							break;
						case 3: qpalavras[1]++;
							break;
						case 4: qpalavras[2]++;
							break;
						default: qpalavras[3]++;
					}
					tamanhoPalavra = 0;
										
					if (bandeira1 == 0)
						soConsoantes++;	
						
					bandeira1 = 0;
				}	
			}
		}	
			
		printf("%i clientes são do sexo masculino e o nome não começa com a letra 'a'\n", naoA);
		printf("Existem %i palavras com 2 letras\n", qpalavras[0]);
		printf("Existem %i palavras com 3 letras\n", qpalavras[1]);
		printf("Existem %i palavras com 4 letras\n", qpalavras[2]);
		printf("Existem %i palavras com mais de 4 letras\n", qpalavras[3]);
		printf("Existem %i palavras que não contem consoantes\n", soConsoantes);
		ESPERAR; LIMPAR;
	}
}
		
		
	
