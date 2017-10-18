/* 	leia  sexo, cor dos olhos, cabelos, idade 
	ultima linha = -1
	escreva a maior idade
	escreva porcentagem entre 18 e 35 anos inclusive, que tenham olhos verdes, cabelos castanhos OU cabelos louros	
 	PS: Professor, eu não entendi o enunciado do exercício, portanto fiz de acordo com o comentário acima 		*/

#include <stdio.h>
#define VULTIMO -1

int main() {
	int idade, mIdade, i;
	char cOlhos, cCabelos, sexo;
    float  pVerdes, pCastanhos, pLouros;
    
	// leia o primeiro
    printf("Digite idade = -1 para sair \n");
    printf("Insira a idade de 1:" );
	scanf(" %i", &idade);
    mIdade = idade;
    pVerdes = 0;
    pCastanhos = 0;
    pLouros = 0;
    if (idade != VULTIMO) {
            printf("Insira a cor dos cabelos de 1 (C, L ou P):" );
            scanf(" %c", &cCabelos);
            printf("Insira a cor dos olhos de 1 (A, V ou C):" );
            scanf(" %c", &cOlhos);
            printf("Insira o sexo de 1 (M ou F):" );
            scanf(" %c", &sexo);
            i = 1;
            if ((idade >= 18 && idade <= 35) && (sexo == 'F' || sexo == 'f')) {
                if (cOlhos == 'V' || cOlhos == 'v')
                    pVerdes = 1;
                    
                if (cCabelos == 'C' || cCabelos == 'c') 
                    pCastanhos = 1;

                if (cCabelos == 'L' || cCabelos == 'l') 
                    pLouros = 1;
            }
     }	

	// loop leitura
	while (idade != VULTIMO) {
        i++;
		printf("Insira a idade de %i:", i );
	    scanf("%i", &idade);
		if (idade != VULTIMO) {
			if (idade > mIdade) 
				mIdade = idade;
			printf("Insira a cor dos cabelos de %i: (C, L ou P):", i );
            scanf(" %c", &cCabelos);
            printf("Insira a cor dos olhos de %i (A, V ou C):", i );
            scanf(" %c", &cOlhos);
            printf("Insira o sexo de %i (M ou F):", i);
            scanf(" %c", &sexo);
			if ((idade >= 18 && idade <= 35) && (sexo == 'F' || sexo == 'f')) {
                if (cOlhos == 'V' || cOlhos == 'v')
                    pVerdes++;
                    
                if (cCabelos == 'C' || cCabelos == 'c') 
                    pCastanhos++;

                if (cCabelos == 'L' || cCabelos == 'l') 
                    pLouros++;
            }	
        }
    }
	
     pVerdes = ((pVerdes/i)*100);
     pCastanhos = ((pCastanhos/i)*100);
     pLouros = ((pLouros/i)*100;
    
	printf("\nA maior idade: %i", mIdade);
	printf("\nA porcentagem de mocas de 18 a 35 anos com olhos verdes e: %f", pVerdes);
	printf("\nA porcentagem de mocas de 18 a 35 anos com cabelos castanhos e: %f:", pCastanhos);
	printf("\nA porcentagem de mocas de 18 a 35 anos com cabelos louros e: %f", pLouros);
    
    return 0;
}
