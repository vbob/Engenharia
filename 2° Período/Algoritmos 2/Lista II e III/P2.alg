{ 2- Leia um vetor de 50 posições de números inteiros e mostre somente os números positivos }

algoritmo 
    declare vetor[], i numéricos
    para i de 0 a 49 faça
        leia vetor[i]
    fim para
    
    para i de 0 a 49 faça
        teste(vetor[i])
    fim-para
fim-algoritmo

subrotina teste(numero numéricos)
    se(numero > 0)
       então imprima numero
    fim-se
fim-subrotina