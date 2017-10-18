#include<stdio.h>

int main(){
    int     i, j, k, N;
	float 	fator;
	float	soma= 0;

	N = 3; // Ordem da matriz
	
    float   A[3][4] =   	{{3,	-0.1,	-0.2,	 7.85},         // MATRIZ AUMENTADA! 
							{0.1,	 7,		 -0.3,	-19.3},
							{0.3, 	-0.2, 	 10, 	 71.4}};
	
   	float	x[3];
   	
   	printf("\nMATRIZ [A] UTILIZADA: \n");
   	for(k=0; k<N; k++){
   		for(i=0; i<N; i++)
		   printf("%f ", A[k][i]);
		printf("\n");   	
	}
	
	printf("\n\nMATRIZ [B] UTILIZADA:\n");
	for(i=0; i<N; i++)
		printf("%f\n", A[i][N]);
    
// ELIMIN��O PROGRESSIVA	    
    for(k=0; k<N-1; k++){		// La�o exterior se refere a linha pivo que se altera. (linha pivo ou equa��o pivo = equa��o refencial para as elimina��es)
        for(i=(k+1); i<N; i++){		// Este la�o se refere as linhas que sofrer�o as elimina��es, que sempre iniciar� na linha seguinte da linha pivo
                fator = A[i][k]/A[k][k] ;	// fator de corre��o que ser� multiplicada pela linha pivo e ira
                for(j=0; j<=N; j++)		// La�o interno se refere a cada coluna da linha que sofrer�o modifica��es da linha i
                  A[i][j] = A[i][j] - fator*A[k][j];
		}
	}	
    
    x[N-1] =A[N-1][N]/A[N-1][N-1]; // primeira variavel que obtemos

// SUBSTITUI��O PROGRESSIVA
    for(i=N-2; i>=0; i--){	// La�o exterior se refere a linha que receber� os valores das variaveis j� encontradas para desconbrirmos outra. Ela se inicia na penultima e regressa at� a primeira
        soma = 0; 		// soma guarda a soma dos valores das variaveis encontradas 
        for(j=(i+1); j<N; j++)		// La�o interior se refere as colunas da minha linha i
            soma= soma + A[i][j]*x[j];
            
        x[i] = (A[i][N]-soma)/A[i][i];
    }

    printf("\nResultado: " );
    for(i=0; i<N; i++)
         printf("\nX%d =%f \t", i, x[i]);

}
