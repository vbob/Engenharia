#include <stdio.h>
#include <math.h>

int main()
{
	float i = 0, ant = 0, prox = 0, denom = 1, erro = 1, pi = 0;
	printf("Entre com o valor da aproximação: ");
	scanf("%f",&erro);
	pi = 4;
	denom = 3;
	i = -1;
	
	do {
		ant = pi;
		prox = (4 / denom)*i;
		pi = ant + prox;
		denom += 2;
		i = -i;
	} while (fabs(pi - ant) >= erro);
	
	printf("\n %.10f", pi);
	printf("\n");
	return 0;
}
