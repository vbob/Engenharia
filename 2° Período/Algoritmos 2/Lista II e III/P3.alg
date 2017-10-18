{ 3- Faça um programa que carregue uma matriz 10X3 com as notas de dez alunos em três provas. 
Mostre um relatório com o número do aluno (número da linha) e a prova em que cada aluno obteve a menor nota. 
Ao final do relatório, mostre quantos alunos tiveram menor nota na prova 1, quantos alunos tiveram menor nota na prova 2 
e quantos alunos tiveram menor nota na prova 3. }

algoritmo
    declare matriz[][], i, j, m1, m2, m3 numéricos
    
    para i de 0 a 9 faça
        para j de 0 a 2 faça
            leia matriz[i][j]
        fim-para
    fim-para
    
    para i de 0 a 9 faça
       teste(matriz[i][0], matriz[i][1], matriz[i][2], i, &m1, &m2, &m3)
    fim-para
    
    imprima m1, m2, m3
fim algoritmo

subrotina teste(nota1, nota2, nota3, i, *m1, *m2, *m3)
    imprima i
    
    se(nota1 < nota2 && nota 1 < nota3)
        *m1++
        imprima "Prova 1"
    fim-se
    
    se(nota2 < nota1 && nota2 < nota3)
        *m2++
        imprima "Prova 2"
    fim-se
    
    se(nota3 < nota1 && nota3 < nota2)
        *m3++
        imprima "Prova 3"
    fim-se
fim-subrotina   
    
        
            