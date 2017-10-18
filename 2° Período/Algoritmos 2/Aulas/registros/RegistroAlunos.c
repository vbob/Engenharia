
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

struct estudante {
	char nome[255], id[255];
	float porcentagem;
};

void func(struct estudante *registro, char id[255], char nome[255]);

void main() {
	struct estudante registro[255];
	char nome1[255], id1[255];
	int valorLido, pos, achou, i, j;
	valorLido = 0;
	system("clear");
	pos = 0;
	while (valorLido != 4) {
		printf("\n\n****************************");
		printf("\nDigite: ");
		printf("\n1 - Adicione um aluno");
		printf("\n2 - Imprima os alunos cadastrados");
		printf("\n3 - Apagar um aluno");
		printf("\n4 - Sair");
		printf("\n****************************\n\n");
		achou = 0;
		scanf("%i", & valorLido);
		switch(valorLido ) {
			case 1: 
			system("clear");
			printf("\nInsira a ID do aluno: ");
				scanf("%s",id1);
				printf("\nInsira o nome do aluno: ");
				scanf("%s",nome1);
				printf("\n");		
			if (pos == 0)
				func(&registro[pos], id1, nome1);
			else {
				for (i = 0; i <= pos-1; i++) {
					if (strcmp(registro[i].id,id1)==0)
						achou = 1;
				}	
				if (achou == 0)
					func(&registro[pos], id1, nome1);
				if (achou == 1)
					printf("\nRegistro Duplicado\n");
			}
			pos = pos + 1;
			break;
			case 2:
			system("clear");
			printf("Código\t\tAluno\n");
			for (i = 0; i <= pos; i++) {
				printf("%s\t\t%s\n", registro[i].id, registro[i].nome);
			}
			break;
			case 3:
			system("clear");
			printf("Insira a ID do aluno a ser excluido: ");
			scanf("%s", id1);
			for (i = 0; i<=pos-1; i++) {
				if (registro[i].id == id1) {
					for (j = i; j < pos-1; j++) {
						func(&registro[j], registro[j+1].id, registro[j+1].nome);
						printf("\nRegistro excluido com sucesso\n");
						pos = pos-1;
						achou = 1;
					}
				}
				if (achou == 0)
					printf("\nRegistro nao encontrado\n");
				}
		}
	}
}
void func(struct estudante *registro, char id1[255], char nome1[255]) {
		strcpy(registro->id, id1);
		strcpy(registro->nome, nome1);
}
	

	
