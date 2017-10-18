#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define X 2000


int verificaDuplicados(char v1[255], char v2[255]) {
	if (strcmp(v1, v2) == 0)
		return 1;
	else
		return 0;
}

struct Cliente {
	char nome[255], endereco[255], cgc[255];
	int idade, numeroContas[16];
};

struct Conta {
	char cgc[255];
	int tempo;
	float saldo;
};

void main() {
	char nome[255], endereco[255], cgc[255];
	int i, j,contadorContas, cClientes, achou, vLido, negativos, iCliente, tempo, idade, nConta;
	float saldo;
	struct Cliente cliente[X];
	struct Conta conta[2000];
	system("clear");
	vLido = 0;
	while (vLido != 5) {
		negativos = 0;
		achou = 0;
		printf("*******************\n");
		printf("1 - Cadastrar cliente\n");
		printf("2 - Cadastrar conta\n");
		printf("3 - Numero de clientes com saldo negativo\n");
		printf("4 - Numero de clientes com conta ha mais de 10 anos e menos de 30 anos de idade\n");
		printf("5 - Finalizar\n");
		printf("*******************\n\n");
		scanf("%i", &vLido);
		switch (vLido) {
			case 1: system("clear");
				printf("Insira o nome do cliente: ");
				scanf("%s", nome);
				printf("\nInsira o endereco do cliente: ");
				scanf("%s", endereco);
				printf("\nInsira o CGC do cliente: ");
				scanf("%s", cgc);
				printf("\nInsira a idade do cliente: ");
				scanf("%i", &idade);
				if (cClientes < X) {
					for (i = 0; i < cClientes; i++) {
						if (strcmp(cgc, cliente[i].cgc) == 0) {
							achou = 1;
						}
					}
					if (achou == 0) {
						strcpy(cliente[cClientes].nome, nome);
						strcpy(cliente[cClientes].endereco, endereco);
						strcpy(cliente[cClientes].cgc, cgc);
						cliente[cClientes].idade = idade;
						cClientes = cClientes+1;
						cliente[cClientes].numeroContas[0] = 0;
					} 
					else {
						printf("\n\nCGC DUPLICADO\n\n");
					}
				} else 
					printf("\n\nLimite de clientes excedido\n\n");
			break;

			case 2: system("clear");
				printf("Insira o CGC do cliente: ");
				scanf("%s", cgc);
				for (i = 0; i < cClientes; i++) {
					if (strcmp(cgc, cliente[i].cgc) == 0) {
						achou = 1;
						iCliente = i;
					}
				}
				if (achou == 1) {
					printf("\nInsira ha quanto tempo e cliente: ");
					scanf("%i", &tempo);
					printf("\nInsira o saldo atual: ");
					scanf("%f", &saldo);
					strcpy(conta[contadorContas].cgc, cgc);
					conta[contadorContas].tempo = tempo;
					conta[contadorContas].saldo = saldo;
					cliente[iCliente].numeroContas[0] = cliente[iCliente].numeroContas[0]+1;
					cliente[iCliente].numeroContas[cliente[iCliente].numeroContas[0]] = contadorContas;
					contadorContas = contadorContas+1;
				}
				else 
					printf("\n\nCliente nao encontrado\n\n");
			break;

			case 3: system("clear");
				for (i = 0; i < cClientes; i++) {
					//printf("Loop externo");
					for (j = 1; j <= cliente[i].numeroContas[0]; j++) {
					//	printf("Loop interno");
						if (conta[cliente[i].numeroContas[j]].saldo < 0) {
					//		printf("Comparativo");
							achou = 1;
						}
					}
					if (achou == 1){
						negativos = negativos+1;
						achou = 0;
					}							
				}
				printf("\nExistem %i clientes com saldo negativo\n\n", negativos);
			break;

			case 4: system("clear");
				for (i = 0; i < cClientes; i++) {
//					printf("Loop externo");
					for (j = 1; j <= cliente[i].numeroContas[0]; j++) {
//						printf("Loop interno");
						if (cliente[i].idade < 30 && conta[cliente[i].numeroContas[j]].tempo > 10) {
//							printf("Comparativo");
							negativos = negativos + 1;
						}
					}
				}
				printf("\nExiste %i clientes com idade menor que 30 e contas ha mais de 10 anos\n\n", negativos);
		}
	}
}
