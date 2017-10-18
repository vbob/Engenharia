#include <stdio.h>
#include <math.h>
#define TAMANHO 10

void calcular(float* vetorX, float* vetorY);

void main() {
    float vetorX[TAMANHO], vetorY[TAMANHO];
    int i;
    
     for(i = 0; i < TAMANHO; i++) {
        printf("Insira o valor de X, Y para p%i(x, y)", i);
        scanf("%f, %f", &vetorX[i], &vetorY[i]);
    }
    
    calcular(vetorX, vetorY);
}

void calcular(float* vetorX, float* vetorY) {
    float somaXY, somaX, somaY, somaX2, a, b, tamanho;
	int i = 0;
	
    for (i = 0; i < TAMANHO; i++) {
        somaXY = somaXY+(vetorX[i] * vetorY[i]);
        somaX = somaX + vetorX[i];
        somaX2 = somaX2 + pow(vetorX[i], 2);
        somaY = somaY + vetorY[i];
    }
    

    a = ((TAMANHO*somaXY)-(somaX*somaY));
    a = a/((TAMANHO*somaX2)-pow(somaX,2));
    b = ((somaY*somaX2)-(somaX*somaXY));
    b = b/((TAMANHO*somaX2)-pow(somaX, 2));
    
    printf("Na regressão linear do plano cartesiano apresentado dada pela fórmula y=ax+b\nOs coeficientes a = %f e b = %f", a , b);
}
