{ 4- Escreva um programa que leia um vetor de 10 posições e mostre-o. 
Use uma subrotina que inverta o vetor, trocando o 1º elemento com o último, 
o 2º elemento com o penúltimo e assim sucessivamente. Mostre o novo vetor depois da troca }

algoritmo
    declare vetor[], i numéricos
    para i de 0 a 9
        leia vetor[i]
    fim-para
    
    para i de 0 a 4
        troca(&vetor[], i)
    fim-para
    
    para i de 0 a 9
         imprima vetor[i]
    fim-para
fim-algoritmo

subrotina troca(*vetor[], i numéricos)
    declare aux
    aux = vetor[i]
    vetor[i] = vetor[9-i]
    vetor[9-i] = aux
fim-subrotia