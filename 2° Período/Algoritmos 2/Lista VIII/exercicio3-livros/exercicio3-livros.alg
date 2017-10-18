3 - Crie um programa para manter um cadastro de livros. para cada livro armazene seu titulo, autor, ano de publicação e preço. Adicione também opções para listar todos os livros de um determinado autor, listar todos os livros dentro de uma faixa de preço e listar todos os livros publicados num determinado ano.

declare LIVRO registro (titulo literal, autor literal, ano numerico, preco numerico)

algoritmo
	declare escolha inteiro
	imprima  1 - adicionar livro
		 2 - excluir ou editar livro
		 3 - listar livros
		 4 - sair
	leia escolha
	repita
		caso escolha
		     1: adiciona()
		     2: edita()
		     3: relatorio()
		fim-caso
	enquanto (escolha != 4)
fim-algoritmo

adiciona()
	abra ARQUIVO.LIVRO adicionar
	declare livro LIVRO
	leia livro.titulo
	leia livro.autor
	leia livro.ano
	leia livro.preco
	escreva ARQUIVO.livro
	feche ARQUIVO
fim-adiciona()

edita()
	declare nome literal
	leia nome 	
	declare escolha, bandeira inteiro
	bandeira = 0
	imprima 1 - edita
		2 - exclui
		3 - retorne
	imprima escolha
	abra ARQUIVO.LIVRO leitura
	enquanto !ARQUIVO.FDA faça
		se (ARQUIVO.LIVRO.nome == nome)
			bandeira = 1			
			pare
		fim-se
	fim-enquanto

	se escolha == 3
		retorne
	fim-se

	se bandeira == 0 faça
		imprima LIVRO NÃO ENCONTRADO
		retorne
	fim-se	
	
	declare livro LIVRO

	faça
		feche ARQUIVO
		abra ARQUIVO.LIVRO leitura
		abra ARQUIVOTEMP.LIVRO adicionar
		enquanto !ARQUIVO.FDA faça
			se (!ARQUIVO.LIVRO.nome == nome)
				livro.titulo = ARQUIVO.LIVRO.titulo
				livro.autor = ARQUIVO.LIVRO.autor
				livro.ano = ARQUIVO.LIVRO.ano
				livro.preco = ARQUIVO.LIVRO.preco
				escreva ARQUIVOTEMP.livro		
			fim-se
			senao se (escolha == 1) faça
				leia livro.titulo
				leia livro.autor
				leia livro.ano
				leia livro.preco
				escreva ARQUIVO.livro
			fim-se
		fim-enquanto
		feche ARQUIVO
		feche ARQUIVOTEMP
		delete ARQUIVO
		renomeie ARQUIVOTEMP ARQUIVO
	fim-enquanto
fim-edita()

relatorio()
	declare escolha numerico
	declare nome literal
	declare livro LIVRO
	declare precomin, precomax, ano, bandeira, encontrado numericos
	abra ARQUIVO.LIVRO leitura
	imprima 1 - todos os livros
		2 - livros por autor
		3 - livros por preco
		4 - livros por ano
		5 - retorne
	leia escolha
	caso escolha 
	     1: bandeira = 1
	     2: leia nome
	     3:	leia precomin
		leia precomax
	     4: leia ano
	     5: retorne
	fim-caso
	
	encontrado = 0	
	
	enquanto !ARQUIVO.FDA faça
		bandeira = 0
		se (escolha == 1 || (ARQUIVO.LIVRO.autor == nome || (ARQUIVO.LIVRO.preco >= precomin && ARQUIVO.LIVRO.preco <= precomax) || ARQUIVO.LIVRO.ano == ano)) faça
			livro.titulo = ARQUIVO.LIVRO.titulo
			livro.autor = ARQUIVO.LIVRO.autor
			livro.ano = ARQUIVO.LIVRO.ano
			livro.preco = ARQUIVO.LIVRO.preco
			bandeira = 1
			encontrado = 1	
		fim-se
		imprima livro.titulo, livro.autor, livro.ano, livro.preco		
	fim-enquanto
	
	se encontrado == 0
		imprima LIVRO NAO ENCONTRADO
	fim-se
fim relatorio
	
	

