/* 10 funcionarios com codigo, numero de horas trabalhadas, turno de trabalho, categoria, valor da hora trabalhada
leia as informacoes (exceto valor da hora trabalhada), não permitindo categorias inexistentes.
TUDO EM LETRA MAIUSCULA
Calcule o salario inicial com base no valor da hora trabalhada
Calcule o auxilio alimentacao
Mostre todas as informações */

#include <stdio.h>
#define NUMFUNCIONARIOS 10
#define SALARIOMIN 150

int main() {
	int M = NUMFUNCIONARIOS-1;
	int codigo[M], nHoras[M], vHora[M], salario[M], auxilio[M], alimentacao[M];
	char categoria[M], turno[M];
	
	// Loop ler dados dos funcionarios
	for (int i = 0; i < NUMFUNCIONARIOS; i++) {
		printf("Insira o código do funcionário: ");
		scanf("%i", &codigo[i]);
		printf("Insira o número de horas trabalhadas: ");
		scanf("%i", &nHoras[i]);
		printf("Insira o turno (M, V, N): ");
		scanf(" %c", &turno[i]);
		
		// Impedir valores inválidos para turno
		while (turno[i] != 'M' || turno[i] != 'V' || turno[i] != 'N') {
			printf("Insira um turno válido!");
			printf("Insira o turno (M, V, N): ");
			scanf(" %c", &turno[i]);
		}
		
		printf("Insira a categoria (G ou O): ");
		scanf(" c", &categoria[i]);
		
		// Impedir valores invalidos para categoria
		while (categoria[i] != 'O' || categoria[i] != 'G') {
			printf("Insira uma categoria válida!");
			printf("Insira a categoria (G ou O): ");
			scanf(" %c", &categoria[i]);
		}
		
		// Calcular o valor da hora trabalhada
		if ((categoria[i] == 'G') && (turno == 'N'))
			vHora = ((SALARIOMIN/100)*18);
		if (categoria[i] == 'G' && (turno == 'M' || turno[i] == 'V'))
			vHora = ((SALARIOMIN/100)*15);
		if (categoria[i] == 'O' && turno == 'N')
			vHora = ((SALARIOMIN/100)*13);
		if (categoria[i] == 'O' && (turno == 'M' || turno[i] == 'V'))
			vHora = ((SALARIOMIN/100)*10);
			
		// Calcular os valores do salario
		salario[i] = nHoras[i]*vHora[i];
		
		// Calcular os valores da alimentacao
		if (salario[i] < 300)
			alimentacao[i] = ((salario[i]/100)*20);
		if (salario[i] >= 300 && salario[i] <= 600)
			alimentacao[i] = ((salario[i]/100)*15);
		if (salario[i] > 600)
			alimentacao[i] = ((salario[i]/100)*5);		
	}
	
	// Imprimir os dados
	for (int i =0; i < NUMFUNCIONARIOS; i++) {
		printf("\nCodigo: %i", codigo[i]);
		printf("\nNúmero de horas trabalhadas: %i", nHoras[i]);
		printf("\nValor da hora trabalhador: %i", nHoras[i]);
		printf("\Salario: %i", salario[i]);
		printf("\nAlimentação: %i", alimentacao[i]);
		printf("\nTotal a Pagar: %i", salario[i]+alimentacao[i]);
	}
}