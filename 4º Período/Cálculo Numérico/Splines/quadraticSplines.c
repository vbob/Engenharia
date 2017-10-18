#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main() { 
    system("cls");
    int n = 4;  // Número de pontos dados
    float points[4][2] = { {3,   2.5},         // Nesta matriz estão os pontos a serem interpolados
                           {4.5,   1},         // Em ordem crescente no eixo X
                           {7,   2.5},
                           {9,   0.5} };

    // Vamos ter três matrizes, A, coef e b 
    // A[3*(n-1)][3*(n-1)]
    // coef[3*(n-1)] e b[3*(n-1)]

    // Estamos julgando que a1 = 0
    float A[9][9];
    float x[9];
    float b[9];
    float Ared[8][8];

    // Inicializar A com 0
    for (int i = 0; i < (3*(n-1)); i++) {
        for (int j = 0; j < (3*(n-1)); j++)
            A[i][j] = 0;
        b[i] = 0;
        x[i] = 0;
    }

    // Primeiras condicoes
    // a[n+1]x[n]² + b[n+1]x[n] + c[n] = y[n]
    // a[n+1]x[n+1]² + b[n+1]x[n+1] + c[n+1] = y[n+1]

    for (int j = 0; j < (n-1); j++) {
            A[2*j][3*j] = pow(points[j][0], 2);
            
            A[2*j][(3*j) + 1] = points[j][0];
            A[2*j][(3*j) + 2] = 1;
            b[2*j] = points[j][1];

            A[(2*j)+1][3*j] = pow(points[j+1][0], 2);
            A[(2*j)+1][(3*j) + 1] = points[j+1][0];
            A[(2*j)+1][(3*j) + 2] = 1;
            b[(2*j)+1] = points[j+1][1];

            j++;
    }
  
    for (int i = 0; i < (n-2); i++) {
            int j = (2*(n-1)) + i;

            A[j][3*i] = 2*points[i+1][0];
            A[j][(3*i) + 1] = 1;

            A[j][3*(i+1)] = -2*points[i+1][0];
            A[j][(3*(i+1)) + 1] = -1;

            b[j] = 0;
    }

    A[3*(n-1)-1][0] = 1; // Julgando que a1 = 0s

    for (int i = 0; i < (3*(n-1)); i++)
        x[i] = 1;

    for (int o = 0; o < 3*(n-1); o++) {
        for (int l = 0; l < 3*(n-1); l++)
            printf("%.2f\t", A[o][l]);
        printf("* \t %f \t = \t%f", x[o], b[o]);
        printf("\n");
    }

} 
