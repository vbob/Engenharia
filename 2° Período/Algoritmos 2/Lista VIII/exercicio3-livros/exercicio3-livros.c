#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear")
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar(); getchar()

typedef struct {
	char titulo[50];
	char autor[50];
	int ano;
	float preco;
} LIVRO;

void adiciona();
void edita();
void relatorio();

void main() {
	int escolha;
	do {
		LIMPAR;
		printf("*****************************\n");
		printf("1 - Adicionar livro\n");		
		printf("2 - Editar ou excluir livro\n");
		printf("3 - Relatórios\n");
		printf("4 - Sair\n");
		printf("*****************************\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &escolha);
		switch (escolha) {
			case 1: adiciona();
				ESPERAR;
				break;
			case 2: edita();
				ESPERAR;
				break;	
			case 3: relatorio();
				ESPERAR;
			
			default: break;
		}
	} while (escolha != 4);
}

void adiciona() {
	LIMPAR;
	FILE *ARQUIVO;
	ARQUIVO = fopen("livros.bin", "a");
	if (ARQUIVO == NULL) {
		char selecao[2];
		do {
		    LIMPAR;
		    printf("\nCadastro de livros corrompido");
		    printf("\nDeseja apagar o banco de dados atual? (S/N): ");
		    scanf(" %s", selecao);
		    switch (selecao[0]) {
			case 's': system("rm livros.bin");
				  adiciona();
				  return;             
			case 'S': system("rm livros.bin");
				  adiciona();
				  return;                             
			case 'n': return;           
			case 'N': return;
			default: break;      
		    } 
		} while (selecao[0] =! 'n' || selecao[0] != 's');
	    }
	    else {
		LIVRO livro;
		printf("Insira o título do livro: ");
		scanf(" %[^\n]s", livro.titulo);
		printf("\nInsira nome do autor: ");
		scanf(" %[^\n]s", livro.autor);
		printf("\nInsira o ano de publicação do livro: ");
		scanf("%d", &livro.ano);
		printf("\nInsira o preço do livro: R$");
		scanf("%f", &livro.preco);
		fwrite(&livro,sizeof(LIVRO),1,ARQUIVO);
		fclose(ARQUIVO);
	}
}

void edita() {
	LIMPAR;
	LIVRO livro;
	int bandeira;
	char titulo[50];
	printf("Insira o título do livro: ");
	scanf(" %[^\n]s", titulo);
	FILE *ARQUIVO;
	FILE *ARQUIVONOVO;
	ARQUIVO = fopen("livros.bin", "r");
	if (ARQUIVO == NULL) {
		char selecao[2];
		do {	
			LIMPAR;
			printf("\nCadastro de livros corrompido");
			printf("\nDeseja apagar o banco de dados atual? (S/N): ");
			scanf(" %s", selecao);
			switch (selecao[0]) {
				case 's': system("rm livros.bin");
					  return;             
				case 'S': system("rm livros.bin");
				   	  return;
				case 'n': return;           
				case 'N': return;
				default: break;      
			} 
		} while (selecao[0] =! 'n' || selecao[0] != 's');
	}
	else {
		bandeira = 0;
		while (!feof(ARQUIVO)) {
			fread(&livro,sizeof(LIVRO),1,ARQUIVO);
			if (strcmp(livro.titulo, titulo) == 0) {
				bandeira = 1;
				break;
			}
		}	

		if (bandeira == 0) {
			printf("\n\nLIVRO NÃO ENCONTRADO");
			return;
		}
	}
	int escolha;
	LIMPAR;
	printf("Livro selecionado: %s\n\n", titulo);
	printf("********************************\n");
	printf("1 - Editar\n");
	printf("2 - Excluir\n");
	printf("3 - Retornar\n");
	printf("*****************************\n");
	printf("Digite a opção desejada: \n");
	scanf("%d", &escolha);
	if (escolha == 3)
		return;
	
	LIMPAR;

	fclose(ARQUIVO);
	ARQUIVO = fopen("livros.bin", "r");	
	ARQUIVONOVO = fopen("livros.tmp.bin", "a");	
	while (!feof(ARQUIVO)) {
		fread(&livro,sizeof(LIVRO),1,ARQUIVO);
		if (feof(ARQUIVO))
			break;
		if (strcmp(livro.titulo, titulo) != 0) {
			fwrite(&livro,sizeof(LIVRO),1,ARQUIVONOVO);
		}
		else if (escolha == 1) {
			printf("Insira o novo título do livro: ");
			scanf(" %[^\n]s", livro.titulo);
			printf("\nInsira novo nome do autor: ");
			scanf(" %[^\n]s", livro.autor);
			printf("\nInsira o novo ano de publicação do livro: ");
			scanf("%d", &livro.ano);
			printf("\nInsira o novo preço do livro: R$");
			scanf("%f", &livro.preco);
			fwrite(&livro,sizeof(LIVRO),1,ARQUIVONOVO);
		}			
	}

	fclose(ARQUIVONOVO);
	fclose(ARQUIVO);
	remove("livros.bin");
	rename("livros.tmp.bin", "livros.bin");
}	
	
void relatorio() {
	FILE *ARQUIVO;
	FILE *ARQUIVONOVO;
	int bandeira;
	LIVRO livro;
	ARQUIVO = fopen("livros.bin", "r");
	if (ARQUIVO == NULL) {
		char selecao[2];
		do {	
			LIMPAR;
			printf("\nCadastro de livros corrompido");
			printf("\nDeseja apagar o banco de dados atual? (S/N): ");
			scanf(" %s", selecao);
			switch (selecao[0]) {
				case 's': system("rm livros.bin");
					  return;             
				case 'S': system("rm livros.bin");
				   	  return;
				case 'n': return;           
				case 'N': return;
				default: break;      
			} 
		} while (selecao[0] =! 'n' || selecao[0] != 's');
	}

	int escolha;
	LIMPAR;
	printf("RELATORIOS\n\n");
	printf("********************************\n");
	printf("1 - Todos os livros\n");
	printf("2 - Livros por autor\n");
	printf("3 - Livros por preço\n");
	printf("4 - Livros por ano\n");
	printf("5 - Retornar\n");
	printf("*****************************\n");
	printf("Digite a opção desejada: \n");
	scanf("%d", &escolha);
	LIMPAR;
	char autor[50];
	int precomin, precomax, ano;
	precomin = 0;
	precomax = 0 ;
	ano = 0;
	bandeira = 0;
	if (escolha == 5)
		return;
	switch (escolha) {
		case 1: bandeira = 1;
			break;
		case 2: printf("Insira o nome do livro: ");
			scanf(" %[^\n]s", autor);
			break;
		case 3: printf("Insira o preço mínimo do livro: ");
			scanf("%d", &precomin);
			printf("Insira o preço máximo do livro: ");
			scanf("%d", &precomax);
			break;
		case 4: printf("Insira o ano de publicação do livro: ");
			scanf("%d", &ano);
		default: break;
	}
	int encontrado;
	encontrado = 0;
	while (!feof(ARQUIVO)) {
		fread(&livro,sizeof(LIVRO),1,ARQUIVO);
		if (feof(ARQUIVO))
			break;
		if (bandeira == 1 || (strcmp(livro.autor, autor) == 0 || (livro.preco >= precomin && livro.preco <= precomax) || livro.ano == ano)) {
			if (encontrado == 0)
				printf("%-23s %-23s %-20s %-10s\n", "Título", "Autor", "Ano de Publicação", "Preço");
			printf("%-23s%-23s %-18d %2s%-10.2lf\n", livro.titulo, livro.autor, livro.ano, "R$",livro.preco);
			encontrado = 1;
		}
	}
	escolha = 0;
	bandeira = 0;
	if (encontrado == 0)
		printf("LIVRO(S) NÃO ENCONTRADO(S)\n\n");

	fclose(ARQUIVO);
}
	

