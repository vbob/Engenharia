{ Faça um programa que use uma subrotina para receber como parâmetro dois vetores, contendo valores da coordenada x e 
valores da coordenada y de pontos no plano cartesiano. A subrotina deve calcular os coeficientes a e b de uma reta y=ax+b 
que é a regressão linear dos pontos. }

algoritmo 
    declare vetorX[], vetorY[], i, tamanho numericos
    leia tamanho
    
    para i de 0 a tamanho-1
        leia vetorX[i]
        leia vetorY[i]
    fim-para
    
    calcular(vetorX, vetorY, tamanho)
fim-algoritmo

subrotina calcular(vetorX[], vetorY[], tamanho numéricos)
    declare somaXY, somaX, somaY, somaX2 numericos
    
    para i de 0 a tamanho-1
        somaXY = somaXY+(vetorX[i] * vetorY[i])
        somaX = somaX + vetorX[i]
        somaX2 = somaX2 + pow(vetorX[i], 2)
        somaY = somaY + vetorY[i]
    fim-para
    
    a = ((tamanho*somaXY)-(somaX*somaY))/((b*somaX2)-pow(somaX,2))
    b = ((somaY*somaX2)-(somaX*somaXY))/((n*somaX2)-pow(somaX, 2))
    
    imprima a, b
fim-subrotina