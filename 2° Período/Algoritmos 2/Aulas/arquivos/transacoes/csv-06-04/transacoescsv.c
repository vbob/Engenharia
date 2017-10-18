#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear")
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar(); getchar()

typedef struct {
	int cod;
	char transacao[50];
	char material[50];
	int qtde;
	float valorTotal;
	char cliente[50];
	char data[30];
} financeiro;

void ler();
void listar();
void soma();
void compras();
void periodo();
void listarbb();

int lido = 0;
int tamanho;
financeiro fin[50];
	
void main() {
	int selecao;
	char pausa;
	do {
		LIMPAR;
		printf("===================================\n");
		printf("1 - Ler arquivo\n");
		printf("2 - Listar arquivo\n");
		printf("3 - Gasto total com compras\n");
		printf("4 - Material comprado\n");
		printf("5 - Listar por periodo\n");
		printf("6 - Listar valor emprestado do Banco do Brasil\n");
		printf("7 - Sair\n");
		printf("===================================\n");
		scanf("%d", &selecao);
		LIMPAR;
		switch (selecao) {
			case 1: ler(); 
				ESPERAR;
				break;
			case 2: listar();
				ESPERAR;
				break;
			case 3: soma();
				ESPERAR;
				break;
			case 4: compras();
				ESPERAR;
				break;
			case 5: periodo();
				ESPERAR;
				break;
			case 6: listarbb();
				ESPERAR;
				break;
			case 7: break;
			default: printf("OPÇÃO INVÁLIDA"); 
				 ESPERAR;
				 break;
		}
	} while (selecao != 7);
}
				


void ler() {
	FILE *ARQUIVO;
	char linha[100], *str;
	const char s[2] = ",";
	int i;
	i = 0;
	ARQUIVO = fopen("transacoes.csv","r");
	if (ARQUIVO == NULL)
		printf("Problema ao ler transacoes.csv");
	else {
		lido = 1;
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
		tamanho = i-1;
	}
}

void listar() {
	int i;
	if (lido == 0)
		printf("Primeiramente leia o arquivo \n\n");
	else {
		i = 0;
		printf("%-10s  %-15s%-15s %-15s %-15s %-20s %-10s\n", "Código", "Transação", "Material", "Quantidade", "Valor Total", "Cliente", "Data");
		while (i < tamanho) {
			printf("%-10d %-12s %-15s %-15d %-15.2lf %-20s %-10s\n", fin[i].cod,fin[i].transacao,fin[i].material,fin[i].qtde,fin[i].valorTotal,fin[i].cliente,fin[i].data);
			i++;
		}
	}
}

void soma() {
	float soma2 = 0;
	int i, ret;
	if (lido == 0)
		printf("\n\n Primeiramente leia o arquivo \n\n");
	else {
		for (i = 0; i < tamanho; i++) {
			if (strcmp(fin[i].transacao, "compra") == 0)
				soma2 += fin[i].valorTotal;
		}
	printf("\nSOMA = R$%.2lf", soma2);
	}	
}

void compras() {
	int cab = 0, i;
	char c[50];
	if (lido == 0)
		printf("\n\n Primeiramente leia o arquivo \n\n");
	else {
		for (i = 0; i < tamanho; i++) {
			strcpy(c,"compra");
			if (cab == 0) {
				printf("\nMATERIAL COMPRADO\n");
				cab = 1;
			}
			if (!strcmp(fin[i].transacao,c))
				printf("%d\t%s\n", fin[i].cod, fin[i].material);
		}
	cab = 0;
	}
}

void periodo () {
	char dia[2], mes[2], ano[4], data[12], data2[12];
	int datainicial, datafinal, dataaux, bandeira = 0;
	if (lido == 0)
		printf("Primeiramente leia o arquivo \n\n");
	else {
		do {
			printf("\n\nInsira a data inicial no formato dd-mm-aaaa:");
			scanf(" %s", data);
			strcpy(dia, strtok(data,"-"));
			strcpy(mes,strtok(NULL,"-"));
			strcpy(data2,strtok(NULL,"-"));
			strcat(data2,mes);
			strcat(data2,dia);	
			datainicial = atoi(data2); 
			if (datainicial > 29991231) 
				bandeira = 1;
			printf("\n\nInsira a data final no formato dd-mm-aaaa:");
			scanf(" %s", data);
			strcpy(dia, strtok(data,"-"));
			strcpy(mes,strtok(NULL,"-"));
			strcpy(data2,strtok(NULL,"-"));
			strcat(data2,mes);
			strcat(data2,dia);
			datafinal = atoi(data2);
			if (datafinal > 29991231) 
				bandeira = 1;
			if (datainicial > datafinal)
				bandeira = 1;
			if (bandeira == 1)
				LIMPAR;
				printf("DATAS INVALIDAS\nTENTE NOVAMENTE\n\n");
		} while (bandeira == 1);

		int achou = 0, i;
		i = 0;
		LIMPAR;
		while (i < tamanho) {
			strcpy(data, fin[i].data);
			strcpy(dia, strtok(data,"/"));
			strcpy(mes,strtok(NULL,"/"));
			strcpy(data2,strtok(NULL,"/"));
			strcat(data2,mes);
		    strcat(data2,dia);
		    dataaux = atoi(data2);
		    
			if (dataaux >= datainicial && dataaux <= datafinal) {
				if (achou == 0) {
					printf("%-10s  %-15s%-15s %-15s %-15s %-20s %-10s\n", "Código", "Transação", "Material", "Quantidade", "Valor Total", "Cliente", "Data"); 
					achou = 1;
				}
			printf("%-10d %-12s %-15s %-15d %-15.2lf %-20s %-10s\n", fin[i].cod,fin[i].transacao,fin[i].material,fin[i].qtde,fin[i].valorTotal,fin[i].cliente,fin[i].data);
			}
			i++;
		}
	}
}

void listarbb () {
	int i, cab;
	float soma = 0.0;
	if (lido == 0)
		printf("Primeiramente leia o arquivo \n\n");
	else {
		i = 0;
		cab = 0;
		while (i < tamanho) {
			if (strcmp(fin[i].transacao, "emprestimo") == 0 && strcmp(fin[i].cliente, "Banco do Brasil") == 0) {
				if (cab == 0) {
					printf("\nVALOR TOTAL EMPRESTADO DO BANCO DO BRASIL\n");
					cab = 1;
				}
				soma += fin[i].valorTotal;
			}	
			i++;	
		}
		printf("\nSOMA = R$%.2lf", soma);
	}
}

// listagem de todas as compras de um determinao periodo
// contabilizacao da soma total de dinheiro emprestada de Banco do Brasil
