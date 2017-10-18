#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear");
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar(); getchar();
#define SEP ";"

void listar(int op);

typedef struct {
	char placa[10], chassi[17], modelo[25], ano[7], combustivel[15], cor[15];
	float km, mediaConsumo, gastoManut;
} CARROS;

int numeroDeCarros = 0;	
CARROS carros[100];

void main() {
	FILE *arquivo;

	arquivo = fopen("carros.csv", "r");
	
	if (arquivo == NULL) {
		printf("Arquivo inválido");
		LIMPAR;
		ESPERAR;
	}
	
	else {
		int i = 0, escolha = 0;
		char linha[100], *str;
		str = fgets(linha, 100, arquivo);
		while (!feof(arquivo)) {
			strcpy(carros[i].placa, strtok(str, SEP));
			strcpy(carros[i].chassi, strtok(NULL, SEP));
			strcpy(carros[i].modelo, strtok(NULL, SEP));
			strcpy(carros[i].ano, strtok(NULL, SEP));
			strcpy(carros[i].combustivel, strtok(NULL, SEP));
			strcpy(carros[i].cor, strtok(NULL, SEP));
			carros[i].km = atof(strtok(NULL, SEP));
			carros[i].mediaConsumo = atof(strtok(NULL, SEP));
			carros[i].gastoManut = atof(strtok(NULL, SEP));
			str = fgets(linha, 100, arquivo);
			i++;
		}
		numeroDeCarros = i;
		while (escolha != 5) {
			LIMPAR;
			printf("================================================\n");
			printf("1 - Listar todos os carros\n");
			printf("2 - Listar carros por tipo de combustivel\n");
			printf("3 - Mostrar gasto total com manutenção\n");
			printf("4 - Mostrar carros com maior e menor consumo\n");
			printf("5 - Sair\n");
			printf("================================================\n");
			printf("Digite a opção desejada: ");
			scanf("%i", &escolha);

			switch (escolha) {
				case 1: listar(0);
					ESPERAR;
					break;
				case 2: listar(1);
					ESPERAR;
					break;
				case 3: listar(2);
					ESPERAR;
					break;
				case 4: listar(3);
					ESPERAR;
					break;
					
				default:break;
			}
		}	
		
		feof(arquivo);
	}
}

void listar(int op) {
	char combustivel[10];
	float gastoManut = 0, maiorMedia = carros[0].mediaConsumo, menorMedia = carros[0].mediaConsumo;
	int nMaiorMedia, nMenorMedia;
	switch (op) {
		case 0: LIMPAR;
			printf("%-10s %-12s %-18s %-5s %-15s %-10s %-13s %-20s %-20s\n", "Placa", "Chassi", "Modelo", "Ano", "Combustível", "Cor", "Km Rodados", "Média de Consumo", "Gasto com Manutenção"); 
			for (int i = 0; i < numeroDeCarros; i++) 
				printf("%-10s %-12s %-18s %-5s %-15s%-10s %-7.1f%-6s %-5.1f%-15sR$%-20.2f\n", carros[i].placa, carros[i].chassi, carros[i].modelo, carros[i].ano, carros[i].combustivel, carros[i].cor, carros[i].km, "km",  carros[i].mediaConsumo, "km/l", carros[i].gastoManut); 
			break;
		case 1: LIMPAR;
			printf("Digite o combustível desejado: ");
			scanf(" %s", combustivel);
			LIMPAR;
			printf("%-10s %-12s %-18s %-5s %-15s %-10s %-13s %-20s %-20s\n", "Placa", "Chassi", "Modelo", "Ano", "Combustível", "Cor", "Km Rodados", "Média de Consumo", "Gasto com Manutenção");
			for (int i = 0; i < numeroDeCarros; i++) {
				if (strcmp(carros[i].combustivel, combustivel) == 0) 
					printf("%-10s %-12s %-18s %-5s %-15s%-10s %-7.1f%-6s %-5.1f%-15sR$%-20.2f\n", carros[i].placa, carros[i].chassi, carros[i].modelo, carros[i].ano, carros[i].combustivel, carros[i].cor, carros[i].km, "km",  carros[i].mediaConsumo, "km/l", carros[i].gastoManut); 
			}
			break;
		case 2: LIMPAR;
			for (int i = 0; i < numeroDeCarros; i++)
				gastoManut += carros[i].gastoManut;
			printf("O gasto com manutenção foi de R$ %.2f\n", gastoManut);
			break;
		case 3: LIMPAR;
			for (int i = 0; i < numeroDeCarros; i++) {
				if (carros[i].mediaConsumo > maiorMedia) {
					maiorMedia = carros[i].mediaConsumo;
					nMaiorMedia = i;
				}
				if (carros[i].mediaConsumo < menorMedia) {
					menorMedia = carros[i].mediaConsumo;
					nMenorMedia=i;
				}
			}
			printf("A maior média é do %s de placa %s com %.2f km/l de media\n", carros[nMaiorMedia].modelo, carros[nMaiorMedia].placa, carros[nMaiorMedia].mediaConsumo);
			printf("A menor média é do %s de placa %s com %.2f km/l de media\n", carros[nMenorMedia].modelo, carros[nMenorMedia].placa, carros[nMenorMedia].mediaConsumo);
			break;
		default: break;
	}
}
