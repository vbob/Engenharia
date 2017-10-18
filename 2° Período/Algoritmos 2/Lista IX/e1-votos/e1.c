#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear")
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar(); getchar()
#define NCANDIDATOS 5


void main() {
	LIMPAR;
	FILE *arquivo;
	arquivo = fopen("votos.txt", "r");
	int candidatos[NCANDIDATOS] = {1,2,3,4,5}; // Aqui será verificado o codigo dos candidatos
	int votos[NCANDIDATOS + 2];
	char linha[100], *str;
	int bandeira;
	for (int i = 0; i < NCANDIDATOS+2; i++) // inicializar matriz de votos
	votos[i] = 0;
	
	if (arquivo == NULL) {
		printf("\nARQUIVO INVALIDO");
		ESPERAR;
		LIMPAR;
	}
	
	else {
		while (!feof(arquivo)) {
			bandeira = 0;
			str = fgets(linha, 100, arquivo);
			if (!feof(arquivo)) {
				for (int i = 0; i < NCANDIDATOS; i++) {
					if (atoi(str) == candidatos[i]) {
						votos[i]++;
						bandeira = 1;
					}
				}
				if (bandeira == 0)
					votos[NCANDIDATOS+1]++;
			}
		}
	}
	
	fclose(arquivo);
	int maisVotado = 0;
	int menosVotado = 0;
	
	for (int i = 0; i < NCANDIDATOS; i++) {
		if (votos[i] > votos[maisVotado])
			maisVotado = i;
		if (votos[i] < votos[menosVotado])
			menosVotado = i;
	}
		
	
	printf("Mais votado: Candidato %d, com %d votos\n", candidatos[maisVotado], votos[maisVotado]);
	printf("Menos votado: Candidato %d, com %d votos\n", candidatos[menosVotado], votos[menosVotado]);
        printf("Nulos: %d votos\n", votos[NCANDIDATOS+1]);
         
        ESPERAR;
}
			
					
	
	
	
