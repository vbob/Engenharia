#include <stdio.h>
#define TAM 100

void convertaHorasEmSegundos(int *horario);
void convertaSegundosEmHoras(int horario);

void main(){
    int numero[TAM], entrada[TAM], saida[TAM], duracao[TAM], i, j;
    i = 0;
    do {
        printf("Para sair digite o numero do funcionario negativo");
        printf("\nInsira o numero do funcionario: ");
        scanf("%i", &numero[i]);
        if (numero[i] > 0) {
            printf("Insira a hora de inicio (HHMMSS): ");
            scanf("%i", &entrada[i]);
            printf("Insira a hora de termino (HHMMSS): ");
            scanf("%i", &saida[i]);
            convertaHorasEmSegundos(&entrada[i]);
            convertaHorasEmSegundos(&saida[i]);	
       }
	i++;
    } while (numero[i-1] > 0);
	i -= 1;
    printf("Funcionario\tInicio\t\t\tFinal\t\t\tDuracao\n");
    for (j = 0; j < i; j++) {
        duracao[j] = saida[j]-entrada[j];
        printf("%i\t\t", numero[j]);
	convertaSegundosEmHoras(entrada[j]);
	printf("\t\t");
	convertaSegundosEmHoras(saida[j]);
	printf("\t\t");
	convertaSegundosEmHoras(duracao[j]);     
	printf("\n"); 
    }
}

void convertaHorasEmSegundos(int *horario) {
    int horas, minutos, segundos;
    segundos = (*horario)%100;
	*horario -= segundos;
	minutos = (*horario%10000)/100;
	*horario -= minutos*100;
	horas = (*horario/10000);
	*horario = (horas*3600) + (minutos*60) + segundos;  
}

void convertaSegundosEmHoras(int horario) {
    int horas, minutos, segundos;
    horas = horario/3600;
	horario -= horas*3600;
	minutos = horario/60;
	segundos = horario-minutos*60;
    printf("%ih %im %is", horas, minutos, segundos);
}
