#include <stdio.h>

void teste(int nota1, int nota2, int nota3, int i, int* m1, int* m2, int* m3);

int main() {
    int matriz[10][3];
    int i, j, m1, m2, m3;
    
	m1 = 0;
	m2 = 0;
	m3 = 0;	

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            printf("Insira a nota %i do aluno %i ", j, i);
            scanf("%i", &matriz[i][j]);
        }
    }
    
    for (i = 0; i < 10; i++)
        teste(matriz[i][0], matriz[i][1], matriz[i][2], i, &m1, &m2, &m3);
    
    printf("\nMenor nota na Prova 1: %i alunos\nMenor nota na Prova 2: %i alunos\nMenor nota na Prova 3: %i alunos\n", m1, m2, m3);   
}

void teste(int nota1, int nota2, int nota3, int i, int* m1, int* m2, int* m3) {
    printf("\nAluno %i: ", i);
    
    if(nota1 < nota2 && nota1 < nota3) {
        m1 = m1+1;
        printf("Menor nota na Prova 1");
    }
    
    if(nota2 < nota1 && nota2 <= nota3) {
        m2 = m2+1;
        printf("Menor nota na Prova 2");
    }
    
    if(nota3 < nota2 && nota3 < nota1) {
        m3 = m3+1;
        printf("Menor nota na Prova 3");
    }  
}
