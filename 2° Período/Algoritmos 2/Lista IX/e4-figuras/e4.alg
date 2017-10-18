algoritmo
	abra ARQUIVO.ENTRADA.TXT
	declare linha literal
	linha = leia ARQUIVO.ENTRADA.TXT.LINHA1
	declare bandeira, tipoFigura, base, altura, raio, somaAreas, nFiguras numerico
	
	bandeira = 0
	i = 0
	
	se (ARQUIVO.ENTRADA.TXT == NULL)
		imprima "ERRO"
		bandeira = 1		
	fim-se
	
	se (linha == " ")
		imprima "VAZIO"
		bandeira = 1		
	fim-se
	
	feche ARQUIVO.ENTRADA.TXT
	abra ARQUIVO.ENTRADA.TXT
		
	enquanto (bandeira == 0) faça
		linha = leia ARQUIVO.ENTRADA.TXT.LINHA[i]
		se (linha != " ")
			tipoFigura = separe(linha, tabulação)
			caso tipoFigura
				1: base = separe(linha, tabulação)
				   altura = separe(linha, tabulação)
				   somaArea += base*altura;
				2: base = separe(linha, tabulação)
				   altura = separe(linha, tabulação)
				   somaArea += base*altura/2;
				3: raio = separe(linha, tabulação)
				   somaArea += 3.14*(raio*raio)
			fim-caso
		fim-se
		
		se (ARQUIVO.ENTRADA.TXT.FDA)
			quebre
		fim-se
	fim-enquanto
	
	imprima "Media das alturas é: " + somaArea/nFiguras
fim-algoritmo
		
