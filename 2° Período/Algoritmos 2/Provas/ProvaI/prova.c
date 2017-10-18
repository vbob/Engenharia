#include <stdio.h>

void main() {
	int vbase[5], vcres[5];
	int i, j, k, bandeira, maior, menor;
	for (i = 0; i <=4; i++) {
		printf("\n Insira o valor %i: ", i);
		scanf("%i", &vbase[i]);
	}
	maior = vbase[0];
	menor= vbase[0];
	for (i = 0; i <=4 ; i++) {
		bandeira = 0;
		if (i == 0) 
			vcres[0] = vbase[0];
		else {
			for (j = 0; j < i; j++) {
//				if (vbase[i] < vcres[j]) {
				if (vbase[i] < vcres[j] && bandeira == 0) {
					bandeira = 1;
//					for (k = 0; k <= i-j; k++) {
					for (k = 0; k < i-j ; k++) {
//						vcres[(i-k)+1] = vcres[i-k];
						vcres[(i-k)] = vcres[(i-k)-1];
					}
					vcres[j] =  vbase[i];
				}
			}
			if (bandeira == 0)
				vcres[i] = vbase[i];
			if (vbase[i] > maior)
				maior = vbase[i];
			if (vbase[i] < menor)
				menor = vbase[i];
		}
	}

        printf("\nO menor valor é %i", menor);
        printf("\nO maior valor é %i\n", maior);
	for (i = 0; i <5; i++)
		printf("%i ", vcres[4-i]);
        printf("é o vetor em ordem decrescente\n");
	for (i = 0; i<5; i++)
		printf("%i ", vcres[i]);
        printf("é o vetor em ordem crescente\n");
}
