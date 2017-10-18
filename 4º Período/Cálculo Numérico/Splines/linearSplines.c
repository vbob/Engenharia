#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main() { 
    system("cls");
    int n = 4;  // Número de pontos dados
    float points[4][2] = {{3,   2.5},         // Nesta matriz estão os pontos a serem interpolados
                          {4.5,   1},         // Em ordem crescente no eixo X
                          {7,   2.5},
                          {9,   0.5} };
    
    printf("f(x) = \t");
    for (int i = 0; i < n-1; i++) {
        // m = (y-y0) / (x-x0)
        float m = ((points[i+1][1] - points[i][1]) / (points[i+1][0] - points[i][0]));

        // Imprime a função na forma pi(x) = yi + m(x-xi)
        printf("p%d(x) = %.2f + %.2f(x-%.2f) // %.2f < x < %.2f\n\t", i, points[i][1], m, points[i][0], points[i][0], points[i+1][0]);
    }

    float xAproximado = 0;      // Armazena para qual X a função deverá ser aproximada
    printf("\n\nCalcular f(x) aproximado // x = ");
    scanf("%f", &xAproximado);

    int i;
    for (i = 0; i < n-1 && points[i+1][0] < xAproximado; i++); // Procura o intervalo ao qual xAproximado pertence
    float m1 = ((points[i+1][1] - points[i][1]) / (points[i+1][0] - points[i][0]));     // Calcula M para o intervalo

    printf("f(%.2f) ~= %f\n\n", xAproximado, (points[i][1] + m1*(xAproximado - points[i][0]))); // Imprime a resposta
}   
