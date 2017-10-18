#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int cod;
	char transacao[50];
	char material[50];
	int qtde;
	float valorTotal;
	char cliente[50];
	char data[30];
} financeiro;
	

void main() {
	FILE *ARQUIVO;
	char linha[100];
	int tamanho,i;
	financeiro fin[50];
	char *str;
	const char s[2] = ",";
	i = 0;
	ARQUIVO = fopen("transacoes.csv","r");
	fgets(linha,100,ARQUIVO);
	fgets(linha,100,ARQUIVO);
	do {
		str = fgets(linha,100,ARQUIVO);
		if(str != NULL) {
			fin[i].cod=atoi(strtok(str,s));
			strcpy(fin[i].transacao,strtok(NULL,s));
			strcpy(fin[i].material,strtok(NULL,s));
			fin[i].qtde = atoi(strtok(NULL,s));
			fin[i].valorTotal = atof(strtok(NULL,s));
			strcpy(fin[i].cliente,strtok(NULL,s));
			strcpy(fin[i].data,strtok(NULL,s));
		}
		i++;
	} while (str != NULL);
	fclose(ARQUIVO);
	tamanho = i-2;
	i = 0;
	printf("%-10s  %-15s%-15s %-15s %-15s %-20s %-10s\n", "Código", "Transação", "Material", "Quantidade", "Valor Total", "Cliente", "Data");
	while (i < tamanho) {
		printf("%-10d %-12s %-15s %-15d %-15.2lf %-20s %-10s\n", fin[i].cod,fin[i].transacao,fin[i].material,fin[i].qtde,fin[i].valorTotal,fin[i].cliente,fin[i].data);
		i++;
	}
}
		

