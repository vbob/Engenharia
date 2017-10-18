#include<stdio.h>

int main(){
    int     i, j, k, N;
	float 	fator;
	float	soma= 0;
    
    printf("METODO DE GAUSS");
   // printf("\nInsira a ordem da matriz (feita apenas por coeficientes de vari�veis) : ");
   // scanf("%d", &N );

    float A[3][4]   = { { 3,  -0.1, -0.2, -7.85},
                    {0.1, 7, 0.3, -19.3},
                    {0.3,  -0.2,  10, 71.4}};
   	float	x[3];
N = 3;
    /*printf("\nInsira os elementos da matriz [A]: \n\n");
    for(i=1;i<=N;i++){
        for(j=1;j<=(N+1);j++)
        {
            printf("A[%d][%d]:", i, j);
            scanf("%f", &A[i][j]);
        }
    */
    
// ELIMIN��O PROGRESSIVA	    
    for(k=0; k<N; k++){		// La�o exterior se refere a linha pivo que se altera. (linha piv� = linha refencial para as elimina��es)
        for(i=(k+1); i<=N; i++){		// Este la�o se refere as linhas que sofrer�o as elimina��es
                fator = A[i][k]/A[k][k] ;	// fator de corre��o que ir� modificar os elementos das linha que tiveram elimina��es	
                for(j=0; j<=(N); j++)		// La�o interno se refere a cada coluna que sofrer�o modifica��es da linha i
                  A[i][j] = A[i][j] - fator*A[k][j];
		}
	}	
    
    x[N] =A[N][N+1]/A[N][N]; // primeira variavel que obtemos

// SUBSTITUI��O PROGRESSIVA - um pouco diferente do portugol do professor
    for(i=N-1; i>=0; i--){
        soma = 0;
        for(j=(i); j<=N; j++)
            soma= soma + A[i][j]*x[j];
            
        x[i] = (A[i][N+1]-soma)/A[i][i];
    }

    printf("\nResultado: \n " );
    for(i=1; i<=N; i++)
         printf("\nX%d =%f \t", i, x[i]);
         
}
