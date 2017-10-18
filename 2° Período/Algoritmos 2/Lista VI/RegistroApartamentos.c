#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define X 20

struct Imovel {
	char identificacao[255];
	double imposto;
	int mesesatraso;
};

void main() {
	int tabela[5][3] = {{0, 50,1},{50, 180, 2},{180,500,4},{500,1200,7},{1200,99999999,10}};
	char identific[255];
	struct Imovel imovel[X];
	int i, achou, mesesatraso, n, vLido, contador;
	double imposto, multa;
	vLido = 0;
	contador = 0;
	system("clear");
	while (vLido != 3) {
		printf("*******************\n");
		printf("1 - Registrar imovel \n");
		printf("2 - Registrar multa\n");
		printf("3 - Finalizar\n");
		printf("*******************\n");
		scanf("%d", &vLido);
		achou = 0;
		switch(vLido) {
			case 1: system("clear");
			printf("Insira a identificacao do imovel: ");
			scanf("%s", identific);
			if (contador < X) {
				for (i = 0; i <= contador; i++) {
					if (strcmp(identific, imovel[i].identificacao) == 0) {
						achou = 1;
					}
				}
				if (achou == 0) {
					printf("\nInsira o valor de imposto devido: ");
					scanf("%lf", &imposto);
					printf("\nInsira os meses em atraso: ");
					scanf("%i", &mesesatraso);
					contador = contador+1;
					strcpy(imovel[contador].identificacao, identific);
					imovel[contador].imposto = imposto;
					imovel[contador].mesesatraso = mesesatraso;
				}
				else
			 		printf("\nIMOVEL DUPLICADO\n\n");
			}
			else
				printf("\nLIMITE DE IMOVEIS EXCEDIDO\n\n");
			break;
			case 2: system("clear");
				printf("Insira a identificacao: ");
				scanf("%s", identific);
				for (i = 0; i <= contador; i++) {
                                        if (strcmp(identific, imovel[i].identificacao) == 0) {
                                                achou = 1;
						n = i;
                                        }
                                }
				if (achou == 1) {
					printf("\nIdentificacao\t\tImposto Devido\t\t\tMesesatraso\t\tMulta\n");
					for (i = 0; i < 4; i++){
						if (imovel[n].imposto >= tabela[i][0] && imovel[n].imposto<tabela[i][1]) {
							printf("\nde %d a %d, %d\n", tabela[i][0],tabela[i][1], (tabela[i][2]/100));
							multa = (imovel[n].imposto)*((tabela[i][2])/100)*(imovel[n].mesesatraso);
						}
					}
					printf("%s\t\t\t%lf\t\t\t%i\t\t\t%lf\n\n", imovel[n].identificacao, imovel[n].imposto, imovel[n].mesesatraso, multa);
				}
				break;
			}
		}
	}
