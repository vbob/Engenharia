#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    system("cls");    
    int n = 3; // O número de equações (linhas do sistema linear)

    // Declara a matriz com os coeficientes e respostas
    float A[3][3]   = { { -8,  2, -2},
                        {2, -6, -1},
                        {-3,  -2,  7}};
    
    // Declara matriz com os resultados
    float b[3][1]  = {{  -20},
                      {  -38},
                       { -34}};

    // Define o erro máximo absoluto esperado    
    float erroMax = 0.001;

    // Declarar o vetor de chute inicial
    float x[3][1] = { { 0}, 
                      { 0},
                      { 0} };

    // Declara bandeira que indica quando parar
    float erro = 0; 
   
    int rel = 1;
    int fr = 1.2;

    // Loop do método
    do {   
        // Define matriz onde ficará a resposta aproximada 
        float bAprox[3][1] = {{0}, {0}, {0}};

        erro = 0;

        // Loop em i
        for (int i = 0; i < n; i++) {
            float k = 0;

            // Faz k ser o somatório de Aij * xj 
            for (int j = 0; j < n; j++) {
                if (j != i)
                    k += A[i][j]*x[j][0];
            }

            // Faz xNovo ser (bi - k) / Aii
            float xNovo = (1/A[i][i]) * (b[i][0] - k);

            // Aplica o fator de relaxamento se desejado
            if (rel == 1) 
                x[i][0] = fr * xNovo + ((1-fr)*x[i][0]);
            else 
                x[i][0] = xNovo;
        }
        

        // Calcula a resposta aproximada e calcula o erro absoluto subtraindo bAprox de bReal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                bAprox[i][0] += A[i][j]*x[j][0];
            if (fabs(b[i][0] - bAprox[i][0]) > erroMax)
                erro = 1;
        }
        
        printf("\nx = {%f, %f, %f}\n", x[0][0], x[1][0], x[2][0]);
        printf("bAprox = {%f, %f, %f}\n", bAprox[0][0], bAprox[1][0], bAprox[2][0]);
    } while (erro != 0);
    
}