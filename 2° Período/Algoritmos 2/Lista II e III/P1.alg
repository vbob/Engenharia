{ 1- Faça um programa que carregue um vetor com 15 elementos inteiros e verifique a existência de elementos iguais a 30, 
mostrando as posições em que esses elementos apareceram. }

algoritmo 
    declare vetor, i numéricos
    
    para i de 0 a 14 faça
        leia vetor[i]
    fim-para
    
    para i de 0 a 14 faça
        teste(vetor[i], i)
    fim-para
fim-subrotina

subrotina teste(numero, i numéricos)
    se(numero = 30)
        então imprima i
    fim-se
fim-subrotina