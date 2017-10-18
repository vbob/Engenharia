#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear")
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar()

void main() {
	LIMPAR;
	FILE *ARQUIVO;
	
	char linha[100], *str;
	const char s[2] = "\t";
	int tipoFigura, i = 0, nFiguras = 0;
	
	float base, altura, raio, somaArea = 0;
	
	ARQUIVO = fopen("entrada.txt","r");
	if (ARQUIVO == NULL)
		printf("Problema ao ler o arquivo");
	else {
		do {
			str = fgets(linha,100,ARQUIVO);
			
			if(str != NULL) {
				tipoFigura=atoi(strtok(str,s));
				switch(tipoFigura) {
					case 1: base = atof(strtok(NULL,s));
					   	altura = atof(strtok(NULL,s));
				   		somaArea += base*altura;	
				   		break;
					case 2: base = atof(strtok(NULL,s));
					   	altura = atof(strtok(NULL,s));
				   		somaArea += base*altura/2;
				   		break;
					case 3: raio = atof(strtok(NULL,s));
				   		somaArea += 3.14*(raio*raio);
				}
				nFiguras++;
			}

			i++;
		} while (!feof(ARQUIVO));
	
		fclose(ARQUIVO);
	}

	if (nFiguras != 0)
		printf("\nA media das áreas é: %f", somaArea/nFiguras);	
	else 
		printf("\nArquivo vazio");
	ESPERAR;
	LIMPAR;
}



