#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear")
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar()
#define SEP ","

float bytesToMega(float bytes);

typedef struct {
	char nome[100];
	float uso;
} USUARIO;

void main() {
	LIMPAR;
	FILE* arquivo;
	
	USUARIO usuario[10];
	
	char linha[100], *str;
	float usoTotal = 0;
	
	arquivo = fopen("usuarios.txt", "r");
	
	if (arquivo == NULL) {
		printf("\nERRO AO ABRIR O ARQUIVO");
		ESPERAR;
		LIMPAR;
	}
	
	
	
	else {
		int i = 0;
		str = fgets(linha, 100, arquivo);
		while(!feof(arquivo)) { 
			strcpy(usuario[i].nome, strtok(str, SEP));
			usuario[i].uso = bytesToMega(atof(strtok(NULL, SEP)));
			str = fgets(linha, 100, arquivo);
			usoTotal += usuario[i].uso;
			i++;
		}
		
		printf("Uso do espaço em disco pelos usuários ----------------------------\n\n");
		printf("%-5s %-15s  %-20s %-15s\n", "Nr.", "Usuário", "Espaço utilizado", "% do uso");
		for (int j = 0; j < i; j++) 
			printf("%-5i %-15s %-10.2lf%-10s%-3.2f%-12s\n", j+1, usuario[j].nome, usuario[j].uso, "MiB", usuario[j].uso*100/usoTotal, "\%");
		printf("\nUso total do disco: %.2f MiB\n", usoTotal);
		printf("Uso médido do disco: %.2f MiB\n", usoTotal/i+1);
	}
	
	fclose(arquivo);
	
	ESPERAR;

	LIMPAR;
}

float bytesToMega(float bytes) {
	return bytes/(1024*1024);
}


