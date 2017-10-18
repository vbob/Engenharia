#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#define INICIALIZAR ArquivoStruct Cache; FILE *nome; nome = fopen("nome.bin", "r"); fread(&Cache,sizeof(ArquivoStruct),1,nome); fclose(nome)
#define REINICIALIZAR nome = fopen("nome.bin", "r"); fread(&Cache,sizeof(ArquivoStruct),1,nome); fclose(nome)
#define ARQUIVO Cache.arquivo

typedef struct {
		int dia;
		int mes;
	} ANIVERSARIO;

typedef struct
{
	char nome[50];
	int telefone;
	char logradouro[50];
	int numero;
	char cidade[50];
	char estado[50];
	ANIVERSARIO aniversario;
} endereco;

typedef struct
{
	char arquivo[50];
} ArquivoStruct;

void inserir();
void listar();
void buscar();
void remover();
void editar();
void DefinirArquivo();
void Concatenar();

void main()
{
	int selecao;
	char pausa[50];
	DefinirArquivo();
	do
	{
		INICIALIZAR;
		system("clear");
		printf("****************************\n");
		printf("\nArquivo atual: %s\n\n", ARQUIVO);
		printf("****************************\n");
		printf("1 - Inserir endereco\n");
		printf("2 - Listar enderecos\n");
		printf("3 - Buscar por nome\n");
		printf("4 - Editar por nome\n");
		printf("5 - Remover por nome\n");
		printf("6 - Organizar os registros\n");
		printf("7 - Mudar o arquivo que a ser lido\n");
		printf("8 - Sair\n");
		printf("****************************\n");
		printf("\nDigite a opcao: ");
		scanf("%d",&selecao);
		system("clear");
		switch (selecao)
		{
		case 1:
			inserir();
			printf("\n\nInserido com sucesso");
			printf("\nPressione qualquer tecla para sair");
			getchar();
			getchar();
			break;
		case 2:
			listar();
			printf("\n\nPressione qualquer tecla para sair");
			getchar();
			getchar();
			break;
		case 3:
			buscar();
			printf("\n\nPressione qualquer tecla para sair");
			getchar();
			getchar();
			break;
		case 4:
			editar();
			printf("\n\nEditado com sucesso");
			printf("\nPressione qualquer tecla para sair");
			getchar();
			getchar();
			break;
		case 5:
			remover();
			printf("Removido com sucesso");
			printf("\n\nPressione qualquer tecla para sair");
			getchar();
			getchar();
			break;
		case 6:
			Concatenar();
			break;
		case 7: 
			DefinirArquivo();
		default:
			break;
		}
	}
	while (selecao != 8);
}

void inserir()
{
	INICIALIZAR;
	FILE *meuArquivo;
	endereco end;
	int bandeira;
	meuArquivo = fopen(ARQUIVO,"a");
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo %s\n", ARQUIVO);
	else
	{
		printf("\nNome: ");
		scanf(" %[^\n]s]", end.nome);
		printf("\nTelefone: ");
		scanf("%d", &end.telefone);
		printf("\nLogradouro: ");
		scanf(" %[^\n]s]", end.logradouro);
		printf("\nNumero: ");
		scanf("%d", &end.numero);
		printf("\nCidade: ");
		scanf(" %[^\n]s", end.cidade);
		printf("\nEstado: ");
		scanf(" %[^\n]s", end.estado);
		do {
			bandeira = 0;
			printf("\nData de Aniversário [formato DD-MM]: ");
			scanf("%d-%d", &end.aniversario.dia, &end.aniversario.mes);
			if (end.aniversario.mes > 12 || end.aniversario.mes < 1) {
				printf("\n\nMes invalido");
				printf("\nTENTE NOVAMENTE\n\n");
				bandeira = 1;
			}
			if (end.aniversario.mes == (4 || 6 || 9 || 11) && end.aniversario.dia > 30) {
				printf("\n\nDia invalido");
				printf("\nTENTE NOVAMENTE\n\n");
				bandeira = 1;
			}
			if (end.aniversario.mes == 2 && end.aniversario.dia > 29) {
				printf("\n\nDia invalido");
				printf("\nTENTE NOVAMENTE\n\n");
				bandeira = 1;
			}
		} while (bandeira == 1);
		fwrite(&end,sizeof(endereco),1,meuArquivo);
		fclose(meuArquivo);
	}
}

void listar()
{
	INICIALIZAR;
	FILE *meuArquivo;
	endereco end;
	meuArquivo = fopen(ARQUIVO,"r");
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo %s\n", ARQUIVO);
	else
	{
		printf("%-25s %-10s %-35s %-10s %-35s %-10s %-5s", "NOME", "TELEFONE", "LOGRADOURO", "NUMERO", "CIDADE", "ESTADO", "ANIVERSARIO");
		fread(&end,sizeof(endereco),1,meuArquivo);
		while(!feof(meuArquivo))
		{
			if (strcmp(end.nome, "0") != 0)
				printf("\n%-25s %-10d %-35s %-10d %-35s %-10s %-d-%-d", end.nome, end.telefone, end.logradouro, end.numero, end.cidade, end.estado, end.aniversario.dia, end.aniversario.mes);
			fread(&end,sizeof(endereco),1,meuArquivo);
		}
		fclose(meuArquivo);
	}
}

void buscar()
{
	INICIALIZAR;
	FILE *meuArquivo;
	endereco end;
	meuArquivo = fopen(ARQUIVO,"r");
	char pesquisa[50];
	int bandeira;
	bandeira = 0;
	printf("Digite o nome a ser pesquisado ");
	scanf(" %[^\n]s", pesquisa);
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
	else
	{
		while(!feof(meuArquivo) && pesquisa!="0" &&  bandeira == 0)
		{
			fread(&end,sizeof(endereco),1,meuArquivo);
			if (strcmp(end.nome, pesquisa) == 0)
			{
				system("clear");
				printf("%-25s %-10s %-35s %-10s %-35s %-10s %-5s", "NOME", "TELEFONE", "LOGRADOURO", "NUMERO", "CIDADE", "ESTADO", "ANIVERSARIO");
				if (feof(meuArquivo))
					break;
			printf("\n%-25s %-10d %-35s %-10d %-35s %-10s %-2d%s%-2d", end.nome, end.telefone, end.logradouro, end.numero, end.cidade, end.estado, end.aniversario.dia, "-", end.aniversario.mes);
				bandeira = 1;
			}
		}
		if (bandeira == 0)
			printf("\nRegistro nao encontrado");
		fclose(meuArquivo);
	}
}

void editar()
{
	INICIALIZAR;
	FILE *meuArquivo;
	FILE *meuArquivoNovo;
	endereco end;
	meuArquivo = fopen(ARQUIVO,"r+");
	meuArquivoNovo = fopen("exemplo2.bin","a");
	char pesquisa[50];
	int bandeira;
	bandeira = 0;
	printf("Digite o nome a ser editado ");
	scanf(" %[^\n]s", pesquisa);
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
	else
	{
		while(!feof(meuArquivo) && pesquisa != "0")
		{
			fread(&end,sizeof(endereco),1,meuArquivo);
			if (strcmp(end.nome, pesquisa) == 0)
			{
				system("clear");
				printf("\nINSIRA OS DADOS DO NOVO REGISTRO\n");
				printf("\nNome: ");
				scanf(" %[^\n]s]", end.nome);
				printf("\nTelefone: ");
				scanf("%d", &end.telefone);
				printf("\nLogradouro: ");
				scanf(" %[^\n]s]", end.logradouro);
				printf("\nNumero: ");
				scanf("%d", &end.numero);
				printf("\nCidade: ");
				scanf(" %[^\n]s", end.cidade);
				printf("\nEstado: ");
				scanf(" %[^\n]s", end.estado);
				do {
					bandeira = 0;
					printf("\nData de Aniversário [formato DD-MM]: ");
					scanf("%d-%d", &end.aniversario.dia, &end.aniversario.mes);
					if (end.aniversario.mes > 12 || end.aniversario.mes < 1) {
						printf("\n\nMes invalido");
						printf("\nTENTE NOVAMENTE\n\n");
						bandeira = 1;
					}
					if (end.aniversario.mes == (4 || 6 || 9 || 11) && end.aniversario.dia > 30) {
						printf("\n\nDia invalido");
						printf("\nTENTE NOVAMENTE\n\n");
						bandeira = 1;
					}
					if (end.aniversario.mes == 2 && end.aniversario.dia > 29) {
						printf("\n\nDia invalido");
						printf("\nTENTE NOVAMENTE\n\n");
						bandeira = 1;
					}
				} while (bandeira == 1);
				fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
				fread(&end,sizeof(endereco),1,meuArquivo);
				bandeira = 1;
				if (feof(meuArquivo))
					break;
			}
			else
			{
				fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
			}
		}

		fclose(meuArquivo);
		fclose(meuArquivoNovo);

		if (bandeira == 0)
			printf("\nRegistro nao encontrado");

		else
		{
			remove(ARQUIVO);
			rename("exemplo2.bin",ARQUIVO);
		}

	}
}

void remover()
{
	INICIALIZAR;
	FILE *meuArquivo;
	FILE *meuArquivoNovo;
	endereco end;
	meuArquivo = fopen("Arquivo1","r");
	meuArquivoNovo = fopen("exemplo2.bin","a");
	char pesquisa[50];
	int bandeira;
	bandeira = 0;
	printf("Digite o nome a ser removido ");
	scanf(" %[^\n]s", pesquisa);
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
	else
	{
		while(!feof(meuArquivo))
		{
			fread(&end,sizeof(endereco),1,meuArquivo);
			if (strcmp(end.nome, pesquisa) != 0)
			{
				fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
				fread(&end,sizeof(endereco),1,meuArquivo);
				bandeira = 1;
				if (feof(meuArquivo))
					break;
			}
		}

		fclose(meuArquivo);
		fclose(meuArquivoNovo);

		if (bandeira == 0)
		{
			printf("\nRegistro nao encontrado");
			remove("exemplo2.bin");
		}

		else
		{
			remove(ARQUIVO);
			rename("exemplo2.bin",ARQUIVO);
		}
		system("clear");
	}
}

void DefinirArquivo() {
	ArquivoStruct Cache;
	system("clear")/
	printf("Qual o nome do arquivo que deve ser usado? ");
	scanf(" %[^\n]s", Cache.arquivo);
	system("rm nome.bin");
	FILE *nome;
	nome = fopen("nome.bin", "a");
	strcat(Cache.arquivo, ".bin");
	fwrite(&Cache,sizeof(ArquivoStruct),1,nome);
	fclose(nome);
}

void Concatenar() {
	endereco end, matriz[100];
	char nome[100][100][100], cidade[100][100][100], estado[100][100][100], logradouro[100][100][100];
	int numero[100],telefone[100];
	ANIVERSARIO aniversario[100];
	int nArquivos, i;
	int bandeira;
	FILE *Arquivo1;
	FILE *Arquivo2;
	system("clear");
	do {
		printf("Digite o numero de arquivos que voce deseja unir [caso não queira unir nenhum arquivo, digite 1]: ");
		scanf("%i", &nArquivos);
		if (nArquivos < 2 && nArquivos != 1)
			printf("Valor invalido. Tente novamente.");
	} while (nArquivos < 2 && nArquivos != 1);

	char arquivos[50][50][nArquivos+1];

	system("clear");
	
	do {
		bandeira = 0;
		printf("Digite o nome do arquivo inicial: ");
		scanf(" %[^\n]s", arquivos[0][0]);
		strcat(arquivos[0][0], ".bin");
		Arquivo1 = fopen(arquivos[0][0], "r");
		if (Arquivo1 == NULL) {
			system("clear");
			printf("Arquivo não existe\nTente Novamente\n\n");
			bandeira = 1;
		}
		else {
			fclose(Arquivo1);
		}
	} while (bandeira == 1);

	for (i = 2; i <= nArquivos; i++) {
		do {
			bandeira = 0;
			printf("Digite o nome do %io arquivo: ", i);
			scanf(" %[^\n]s", arquivos[i-1][0]);
			strcat(arquivos[i-1][0], ".bin");
			Arquivo1 = fopen(arquivos[i-1][0], "r");
			if (Arquivo1 == NULL) {
				system("clear");
				printf("Arquivo não existe\nTente Novamente\n\n");
				bandeira = 1;
			}
			else {
				fclose(Arquivo1);
			}
		} while (bandeira == 1);
	}

	do {
		bandeira = 0;
		printf("Digite o nome do arquivo final: ");
		scanf(" %[^\n]s", arquivos[nArquivos][0]);
		strcat(arquivos[nArquivos][0], ".bin");
		for (i = 0; i < nArquivos && bandeira != 1; i++)  {
			system("clear");
			if (arquivos[nArquivos][0] == arquivos[i][0]) {
				printf("\nO nome do arquivo final deve ser diferente dos arquivos iniciais. Tente novamente\n\n");
				bandeira = 1;
			}
		}
	} while (bandeira == 1);

	int selecao, opOrdem, j, k;
	char op[2];

	do {
		system("clear");
		printf("Deseja organizar por ordem de Nomes ou de Cidade\n");
		printf("1) Nome\n");
		printf("2) Estado\n");
		scanf("%i", &opOrdem);
		if (opOrdem != 1 && opOrdem != 2)
			printf("\nValor inválido");
	} while (opOrdem != 1 && opOrdem != 2);	
	
	k = 0;
	for (i = 0; i < nArquivos; i++) {
		Arquivo1 = fopen(arquivos[i][0], "r");
		while (!feof(Arquivo1)) {
			fread(&end,sizeof(endereco),1,Arquivo1);
			if (feof(Arquivo1)) {
				fclose(Arquivo1);
				break;
			}
		
			if (opOrdem == 2)
				strcpy(end.estado, "");
			if (opOrdem == 1) {
				for (j = 0; end.nome[j]; j++)
					end.nome[j] = toupper(end.nome[j]);
				strcpy(estado[k][0], end.estado);

			}

			strcpy(nome[k][0], end.nome);
			strcpy(logradouro[k][0], end.logradouro);
			strcpy(cidade[k][0], end.cidade);
			aniversario[k].dia = end.aniversario.dia;
			aniversario[k].mes = end.aniversario.mes;
			telefone[k] = end.telefone;
			numero[k] = end.numero;
			k++;
		}
	}
	
	char temp[100];
	int tempc;

	Arquivo2 = fopen(arquivos[nArquivos][0], "a");	

	if (opOrdem == 1) {
		for (i = 1; i < k; i++) {
			for (j = 1; j < k; j++) {
				if (strcmp(nome[j-1][0], nome[j][0]) > 0) {
					strcpy(temp, nome[j-1][0]);
	   				strcpy(nome[j-1][0], nome[j][0]);
	    				strcpy(nome[j][0], temp);
	  				strcpy(temp, logradouro[j - 1][0]);
	   				strcpy(logradouro[j - 1][0], logradouro[j][0]);
	    				strcpy(logradouro[j][0], temp);
	  				strcpy(temp, cidade[j-1][0]);
	   				strcpy(cidade[j-1][0], cidade[j][0]);
	    				strcpy(cidade[j][0], temp);
					strcpy(temp, estado[j-1][0]);
	   				strcpy(estado[j-1][0], estado[j][0]);
	    				strcpy(estado[j][0], temp);
					tempc = telefone[j-1];
					telefone[j-1] = telefone[j];
					telefone[j] = tempc;
					tempc = numero[j-1];
					numero[j-1] = numero[j];
					numero[j] = tempc;
					tempc = aniversario[j-1].dia;
					aniversario[j-1].dia = aniversario[j].dia;
					aniversario[j].dia = tempc;
					tempc = aniversario[j-1].mes;
					aniversario[j-1].mes = aniversario[j].mes;
					aniversario[j].mes = tempc;
	 			}
			}
	   	}
	}

	if (opOrdem == 2) {
		for (i = 1; i < k; i++) {
			for (j = 1; j < k; j++) {
				if (strcmp(cidade[j-1][0], cidade[j][0]) > 0) {
					strcpy(temp, nome[j-1][0]);
	   				strcpy(nome[j-1][0], nome[j][0]);
	    				strcpy(nome[j][0], temp);
	  				strcpy(temp, logradouro[j - 1][0]);
	   				strcpy(logradouro[j - 1][0], logradouro[j][0]);
	    				strcpy(logradouro[j][0], temp);
	  				strcpy(temp, cidade[j-1][0]);
	   				strcpy(cidade[j-1][0], cidade[j][0]);
	    				strcpy(cidade[j][0], temp);
					tempc = telefone[j-1];
					telefone[j-1] = telefone[j];
					telefone[j] = tempc;
					tempc = numero[j-1];
					numero[j-1] = numero[j];
					numero[j] = tempc;
					tempc = aniversario[j-1].dia;
					aniversario[j-1].dia = aniversario[j].dia;
					aniversario[j].dia = tempc;
					tempc = aniversario[j-1].mes;
					aniversario[j-1].mes = aniversario[j].mes;
					aniversario[j].mes = tempc;
	 			}
			}
	   	}
		
	}

	for (i = 0; i < k ; i++) {
		if (telefone[i] != 0) {
			strcpy(end.nome, nome[i][0]);
			strcpy(end.logradouro, logradouro[i][0]);
			strcpy(end.cidade, cidade[i][0]);
			strcpy(end.estado, estado[i][0]);
			end.telefone = telefone[i];
			end.numero = numero[i];	
			end.aniversario.dia = aniversario[i].dia;
			end.aniversario.mes = aniversario[i].mes;
			fwrite(&end,sizeof(endereco),1,Arquivo2);
		}
	}
	
	fclose(Arquivo2);
}	
