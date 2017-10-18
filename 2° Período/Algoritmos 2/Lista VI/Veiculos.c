#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

struct Cadastro{
	char proprietario[30], chassi[30], cor[20], combustivel[20], marca[30], modelo[20], placa[9];
	int fabricacao;
};

int main(){
	struct Cadastro veiculo[MAX];
	char proprietario[30], chassi[30], cor[20], combustivel[20], marca[20], modelo[20], placa[9];
	int fabricacao, escolha, i, pos = 0, bandeira =0;
	
	while (escolha != 5){
		printf("\n\n##################################\n");
		printf("\n1- Cadastrar veiculo");
		printf("\n2- Listar veiculos do ano 1990 ou inferior, movidos a gasolina");
		printf("\n3- Listar proprietarios e placas que comecem com A e terminam com 0, 2 ou 7");
		printf("\n4- Trocar usuario");
		printf("\n5- Finalizar\n\n");
		scanf("%d", &escolha);
		switch (escolha){
			case 1: if(pos < MAX){
						bandeira = 0;
						printf("\n\nInsira o nome do proprietario:  ");
						scanf("%s", proprietario);
						printf("\nInsira o Chassi do veiculo  ");
						scanf("%s", chassi);
						printf("\nInsira o marca do veiculo  ");
						scanf("%s", marca);
						printf("\nInsira o modelo do veiculo  ");
						scanf("%s", modelo);
						printf("\nInsira a cor do veiculo  ");
						scanf("%s", cor);
						printf("\nInsira o tipo de combustivel usado no veiculo  ");
						scanf("%s", combustivel);
						printf("\nInsira o ano de fabricacao veiculo  ");
						scanf("%d", &fabricacao);
						printf("\nInsira a placa do veiculo  ");
						scanf("%s", placa);
						
						if (pos != 0){
							for (i=0 ; i<pos ; i++){
								if(strcmp(veiculo[i].chassi, chassi) == 0){
									bandeira = 1;
								}
							}
						}
						if(bandeira == 0){
							strcpy(veiculo[i].chassi, chassi);
							strcpy(veiculo[i].proprietario, proprietario);
							strcpy(veiculo[i].marca, marca);
							strcpy(veiculo[i].modelo, modelo);
							strcpy(veiculo[i].combustivel, combustivel);
							strcpy(veiculo[i].cor, cor);
							veiculo[i].fabricacao = fabricacao;
							strcpy(veiculo[i].placa, placa);
							pos = pos + 1;
						}
						else{
							printf("\n\nEsse veiculo ja esta cadastrado\n");
						}
						
					}
					else{
						printf("\n\nLimite de cadastramento de veiculos foi atingido\n");
					}
			break;
			
			case 2: if(pos != 0){
						bandeira = 0;
						printf("\n\n");
						for(i=0 ; i<pos ; i++){
							//Problema esta comparacao da string com gasolina
							if(veiculo[i].fabricacao <= 1990 && veiculo[i].combustivel == "gasolina"){
								printf("\nProprietario: %s", veiculo[i].proprietario);
								bandeira = 1;
							}
						}
						if(bandeira == 0){
							printf("\n\nNao possui nenhum veiculo cadastrado com tais requisitos\n");
						}
					}
					else{
						printf("\n\nNao ha nenhum veiculo cadastrado\n");
					}
			break;
			
			case 3: if(pos != 0){
						bandeira = 0;
						printf("\n\n");
						for(i=0 ; i<pos ; i++){
							printf("\n\n%s\n\n", veiculo[i].placa);
							// problema aqui
							if(strcmp(veiculo[i].placa[0], 'A')==0){
								if(((strcmp(veiculo[i].placa[8], '0') == 0) || (strcmp(veiculo[i].placa[8], '2')==0) || (strcmp(veiculo[i].placa[8], '7') ==0))){
									printf("\nProprietario: %s	- Placa: %s", veiculo[i].proprietario, placa);
									bandeira = 1;
								}
							}
						}
						if(bandeira == 0){
							printf("Nao ha nenhum veiculo cadastrado com tais requisitos");
						}
				
					}
					else{
						printf("\n\nNao ha nenhum veiculo cadastrado\n");
					}
			break;
			
			case 4: if(pos!=0){
						bandeira = 0;
						printf("\n\nInsira o Chassi do veiculo desejado");
						scanf("%s", chassi);
						for(i=0 ; i<pos ; i++){
							if(strcmp(veiculo[i].chassi, chassi) == 0){
								printf("\nInsira o nome do novo proprietario  ");
								scanf("%s", veiculo[i].proprietario);
								bandeira = 1;
							}
						}
						if(bandeira == 0){
							printf("\n\nVeiculo nao encontrado");
						}	
					}
					else{
						printf("\n\nNao ha nunhum veiculo cadastrado\n");
					}
			break;
		}
		
	}
	return 0;
}
