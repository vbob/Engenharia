#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define X 4

int verificaDuplicado(char v1[255], char v2[255]) {
	//printf("\nA: %s B: %s\n", v1, v2);
	if (strcmp(v1, v2) == 0) {
	//	printf("\nO valor strcmp e %i\n", strcmp(v1, v2)); 
		return 1;
	}
	else
		return 0;
}

struct Assento {
	int tAssentos;
	char nPassageiro[60][255];
};

struct Aviao {
	char numero[255];
};

void main(){
	char nAviao[255], nPassageiro[255];
	int i, j, n, vLido, contadorAssentos[4], achou;
	struct Aviao aviao[X];
	struct Assento assentos[X];
	vLido = 0;
	while (vLido != 6) {
		printf("\n\n************************\n");
		printf("1 - Cadastrar o numero dos avioes\n");
		printf("2 - Cadastrar o numero de lugares disponiveis em cada aviao\n");
		printf("3 - Reservar passagem\n");
		printf("4 - Consultar por aviao\n");
		printf("5 - Consultar por passageiro\n");
		printf("6 - Finalizar\n");
		printf("************************\n\n");
		scanf("%i", &vLido);
		switch(vLido) {
			System("Clear");
			case 1: system("clear"); 
			for (i = 0; i < X; i++) {
				printf("Insira o nome do aviao %i: ", i);
				scanf("%s", nAviao);
				achou = 0;
				if (i == 0) {
					strcpy(aviao[0].numero, nAviao);
					contadorAssentos[0] = 0;
				}
				else {
					for (j = 0; j < i && achou == 0; j++) {
						achou = verificaDuplicado(aviao[j].numero, nAviao);
					} 
					//printf("%i", achou);
					if (achou == 0) {
						strcpy(aviao[i].numero, nAviao);
						contadorAssentos[i] = 0;
					}
					else {
						printf("\nRegistro Duplicado\n\n");
						i = i-1;
					}
				}
			}
				break;
			case 2: system("clear");
				for (i = 0; i < X; i++) {
					printf("\nInsira o numero de assentos disponiveis no aviao %s: ", aviao[i].numero);
					scanf("%i", &assentos[i].tAssentos);
					if (assentos[i].tAssentos > 60) {
						printf("\nNao pode ter mais de 60 assentos por aviao; Insira novamente\n\n");
						i = i-1;
					} 
				}
			break;
			case 3: system("clear");
				printf("\nInsira o numero do aviao: ");
				scanf("%s", nAviao);
				n = 0;
				for (i = 0; i < X; i++) {
					if (verificaDuplicado(nAviao, aviao[i].numero) == 1) {
						achou = 1;
						n = i;
					}
				}
				if (achou == 1) {
					if (contadorAssentos[n] < assentos[n].tAssentos) {
						printf("\nInsira o nome do passageiro: ");
						scanf("%s", assentos[n].nPassageiro[contadorAssentos[n]]);
						contadorAssentos[n] = contadorAssentos[n]+1;
					}
					else
						printf("\n\nAVIAO LOTADO\n\n");
				}
				else 
					printf("\n\nAviao nao encontrado\n\n");
			break;
			case 4: system("clear");
				printf("\nInsira o numero do aviao: ");
				scanf("%s", nAviao);
				n = 0;
				for (i = 0; i < X; i++) {
					if (verificaDuplicado(nAviao, aviao[i].numero) == 1) {
						achou = 1;
						n = i;
					}
				}
				if (achou == 1) {
					printf("\nAssento\t\tNome do Passageiro");
					for (i = 0; i < contadorAssentos[n]; i++) 
						printf("\n%i\t\t%s",i, assentos[n].nPassageiro[i]);
				}
				break;
			case 5: system("clear"); 
				printf("\nInsira o nome do passageiro: ");
				scanf("%s", nPassageiro);
				printf("\n\nAviao\t\tAssento\n");
				for (i = 0; i < X; i++) {
					for  (j = 0; j < contadorAssentos[i]; j++) {
						if (verificaDuplicado(nPassageiro, assentos[i].nPassageiro[j]) == 1)
							printf("%s\t\t%i\n", aviao[i].numero, j);
					}
				}
		}		
	}
}

