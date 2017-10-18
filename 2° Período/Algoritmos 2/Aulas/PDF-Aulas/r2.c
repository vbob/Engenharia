#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 18
#define SMINIMO 112

struct Funcionario {
	char nome[255], turno[2], categoria[2];
	int horastrabalhadas;
	float valor;
};

void main() {
	struct Funcionario funcionario[X];
	char cat[6][2][2] = {{"G","N"},{"G","M"},{"G","V"},{"O","N"},{"O","M"},{"O","V"}};
	float por[6][1] = {{18*0.01},{15*0.01},{15*0.01},{13*0.01},{10*0.01},{10*0.01}};
	float ali[3][3] = {{0,300,20*0.01},{300,600,15*0.01},{600,9999999,5*0.01}};
	system("clear");
	char nome[255], turno[2], categoria[2];
	int escolha, i, j, cFuncionarios, horasmes, achou;
	float valor, sBase, aAlimentacao;	
	cFuncionarios = 0;
	escolha = 0;
	while (escolha != 3) {
		printf("*******************\n");
		printf("1 - Cadastrar funcionario\n");
		printf("2 - Mostre folha de pagamento\n");
		printf("3 - Finalizar\n");
		printf("*******************\n\n");
		scanf("%i", &escolha);
		achou = 0;
		switch (escolha) {
			case 1: system("clear");
				if (cFuncionarios >= X)
					printf("Limite de funcionarios excedido\n\n");
				else 
					printf("Insira o nome do funcionario: ");
					scanf("%s", nome);
					printf("\nInsira o numero de horas trabalhadas no mes: ");
					scanf("%i", &horasmes);
					while (achou == 0) {
						printf("\nInsira o turno de trabalho (M, V ou N): ");
						scanf("%s", turno);
						if (strcmp(turno, "M") == 0 || strcmp(turno, "V") == 0 || strcmp(turno, "N") == 0) {
							while (achou == 0) {
								printf("\nInsira a categoria (O ou G): ");
								scanf("%s", categoria);
								achou = 1;
								if (strcmp(categoria, "O") == 0 || strcmp(categoria, "G") == 0) 
									achou = 1; 
								else {
									printf("\nInsira uma categoria valida\n\n");
									achou = 0;
							}	}
						}
						else {
							printf("\nInsira um turno valido\n\n");
							achou = 0;
						}
					}
					strcpy(funcionario[cFuncionarios].nome, nome);
					funcionario[cFuncionarios].horastrabalhadas = horasmes;
					strcpy(funcionario[cFuncionarios].turno, turno);
					strcpy(funcionario[cFuncionarios].categoria, categoria);
					cFuncionarios = cFuncionarios+1;
					printf("\nFuncionario cadastrado com sucesso\n\n");
					printf("Aperte enter para voltar ao menu...");
					getchar(); 
					getchar();
					system("clear");
					break;
					
					case 2: system("clear");
	                                        printf("NOME\t\tHORAS NO MES\t\tVALOR DA HORA\t\tAUXILIO ALIMENTACAO\t\tSALARIO BRUTO\t\tSALARIO LIQUIDO\n");
						for ( i = 0; i <= cFuncionarios-1; i++) {
							for (j = 0; j < 6; j++) {
								if ((strcmp(funcionario[i].categoria, cat[j][0]) == 0) && (strcmp(funcionario[i].turno, cat[j][1]) == 0)) {
									funcionario[i].valor = por[j][0]*SMINIMO;
									sBase = funcionario[i].horastrabalhadas*por[j][0]*SMINIMO;
								}
							}
							for (j = 0; j < 3; j++){
								if (sBase > ali[j][0] && sBase <= ali[j][1])
									aAlimentacao = sBase*ali[j][2];
							}
							printf("%s\t\t%i\t\t\tR$%.2f\t\t\tR$%.2f\t\t\t\tR$%.2f\t\tR$%.2f\n",funcionario[i].nome, funcionario[i].horastrabalhadas, funcionario[i].valor, aAlimentacao, sBase, (sBase+aAlimentacao));
						}
						printf("\n\n");
		}
	}
}
