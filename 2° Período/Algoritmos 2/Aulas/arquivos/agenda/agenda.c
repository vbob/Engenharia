#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	int telefone;
	char logradouro[50];
	int numero;
	char cidade[50];
	char estado[50];
} endereco;

typedef struct{
	char arquivo[50];
} salvar;

void inserir();
void listar();
void buscar();
void remover();
void editar();
void main() {
	int selecao;
	char pausa[50];
	FILE *nomes;
	salvar RegNomes;
	nomes = fopen("nomes.bin", "r");
	if (nomes == NULL) {
		nomes = fopen("nomes.bin", "a");
		system("clear");
		printf("Qual o nome do arquivo no qual deseja salvar o registro? ");
		scanf(" %[^\n]s", RegNomes.arquivo);
		strcpy(RegNomes.arquivo, strcat(RegNomes.arquivo, ".bin"));
		fwrite(&RegNomes,sizeof(salvar),1,nomes);
		fclose(nomes);
		nomes = fopen("nomes.bin", "r");
	}
	fread(&RegNomes,sizeof(salvar),1,nomes);
	do {
		system("clear");
		printf("****************************\n");
		printf("1 - Inserir endereco\n");
		printf("2 - Listar enderecos\n");
		printf("3 - Buscar por nome\n");
		printf("4 - Editar por nome\n");
		printf("5 - Remover por nome\n");
		printf("6 - Sair\n");
		printf("****************************\n");
		printf("\nDigite a opcao: ");
		scanf("%d",&selecao);
		system("clear");
		switch (selecao) {
			case 1: inserir(); 
				printf("\n\nInserido com sucesso");
				printf("\nPressione qualquer tecla para sair");
				getchar();
				getchar();
				break;
			case 2: listar();
				printf("\n\nPressione qualquer tecla para sair");
                getchar();
                getchar();
				break;
			case 3: buscar();
                printf("\n\nPressione qualquer tecla para sair");
                getchar();
                getchar();
				break;
			case 4: editar();
				printf("\n\nEditado com sucesso");
                printf("\nPressione qualquer tecla para sair");
                getchar();
                getchar();
				break;
			case 5: remover();
				printf("Removido com sucesso");
                printf("\n\nPressione qualquer tecla para sair");
                getchar();
                getchar();
			default: break;
		}
	} while (selecao != 6);
}

void inserir() {
	FILE *meuArquivo;
	endereco end;
	FILE *nomes;
	salvar RegNomes;
	nomes = fopen("nomes.bin", "r");
	fread(&RegNomes,sizeof(salvar),1,nomes);
	meuArquivo = fopen(RegNomes.arquivo,"a");
	fclose(nomes);
	if (meuArquivo == NULL)
		printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
	else {
		printf("\nNome ");
		scanf(" %[^\n]s]", end.nome);
		printf("\nTelefone ");
		scanf("%d", &end.telefone);
		printf("\nLogradouro ");
		scanf(" %[^\n]s]", end.logradouro);
		printf("\nNumero ");
		scanf("%d", &end.numero);
		printf("\nCidade ");
		scanf(" %[^\n]s", end.cidade);
		printf("\nEstado ");
		scanf(" %[^\n]s", end.estado);
		fwrite(&end,sizeof(endereco),1,meuArquivo);
		fclose(meuArquivo);
	}
}

void listar() {
    FILE *meuArquivo;
    endereco end;
    FILE *nomes;
    salvar RegNomes;
    nomes = fopen("nomes.bin", "r");
    fread(&RegNomes,sizeof(salvar),1,nomes);
    meuArquivo = fopen(RegNomes.arquivo,"r");
    fclose(nomes);
    if (meuArquivo == NULL)
        printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
    else {
        printf("%-20s %-10s %-35s %-10s %-20s %-10s", "NOME", "TELEFONE", "LOGRADOURO", "NUMERO", "CIDADE", "ESTADO");
        while(!feof(meuArquivo)) {
            fread(&end,sizeof(endereco),1,meuArquivo);
            if (feof(meuArquivo))
                break;
            if (strcmp(end.nome, "0") != 0) 
                printf("\n%-20s %-10d %-35s %-10d %-20s %-10s", end.nome, end.telefone, end.logradouro, end.numero, end.cidade, end.estado);
        }
        fclose(meuArquivo);
    }
}

void buscar() {
	FILE *meuArquivo;
	endereco end;
	FILE *nomes;
	salvar RegNomes;
	nomes = fopen("nomes.bin", "r");
	fread(&RegNomes,sizeof(salvar),1,nomes);
	meuArquivo = fopen(RegNomes.arquivo,"r");
	fclose(nomes);
	char pesquisa[50];
	int bandeira;
	bandeira = 0;
	printf("Digite o nome a ser pesquisado ");
	scanf(" %[^\n]s", pesquisa);
        if (meuArquivo == NULL)
                printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
        else {
                while(!feof(meuArquivo) && pesquisa!="0" &&  bandeira == 0) {
                        fread(&end,sizeof(endereco),1,meuArquivo);
                        if (strcmp(end.nome, pesquisa) == 0) {
                            system("clear");      
                           printf("NOME TELEFONE LOGRADOURO NUMERO CIDADE ESTADO");;  	                
                            if (feof(meuArquivo))
                	                break;
                	         printf("\n%s %d %s %d %s %s", end.nome, end.telefone, end.logradouro, end.numero, end.cidade, end.estado);
				bandeira = 1;
			            }
                }
	if (bandeira == 0)
		printf("\nRegistro nao encontrado");
    fclose(meuArquivo);
    }
}

void editar() {
        FILE *meuArquivo;
        FILE *meuArquivoNovo;
        endereco end;
	FILE *nomes;
	salvar RegNomes;
	nomes = fopen("nomes.bin", "r");
	fread(&RegNomes,sizeof(salvar),1,nomes);
	meuArquivo = fopen(RegNomes.arquivo,"r+");
	fclose(nomes);
        meuArquivoNovo = fopen("exemplo2.bin","a");
        char pesquisa[50];
        int bandeira;
        bandeira = 0;
        printf("Digite o nome a ser editado ");
        scanf(" %[^\n]s", pesquisa);
        if (meuArquivo == NULL)
                printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
        else {
                while(!feof(meuArquivo) && pesquisa != "0") {
                        fread(&end,sizeof(endereco),1,meuArquivo);
               	        if (strcmp(end.nome, pesquisa) == 0) {
                            system("clear");
				            printf("\nINSIRA OS DADOS DO NOVO REGISTRO\n"); 
                            printf("\nNome ");
                            scanf(" %[^\n]s]", end.nome);
                            printf("\nTelefone ");
                            scanf("%d", &end.telefone);
                            printf("\nLogradouro ");
                            scanf(" %[^\n]s]", end.logradouro);
                            printf("\nNumero ");
                            scanf("%d", &end.numero);
                            printf("\nCidade ");
                            scanf(" %[^\n]s", end.cidade);
                            printf("\nEstado ");
                            scanf(" %[^\n]s", end.estado);
                            fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
                            fread(&end,sizeof(endereco),1,meuArquivo);
                            if (feof(meuArquivo))
                                break;
                            bandeira = 1;
                        }
                        else {
                             fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
                        }
               }
        fclose(meuArquivo);
        if (bandeira == 0)
                printf("\nRegistro nao encontrado");
                
        else { 
            remove(RegNomes.arquivo);
	    rename("exemplo2.bin",RegNomes.arquivo);	
        }
        fclose(meuArquivoNovo);
    }
}

void remover() {
        FILE *meuArquivo;
        FILE *meuArquivoNovo;
        endereco end;
        FILE *nomes;
	salvar RegNomes;
	nomes = fopen("nomes.bin", "r");
	fread(&RegNomes,sizeof(salvar),1,nomes);
	meuArquivo = fopen(RegNomes.arquivo,"r");
	fclose(nomes);
        meuArquivoNovo = fopen("exemplo2.bin","a");
        char pesquisa[50];
        int bandeira;
        bandeira = 0;
        printf("Digite o nome a ser removido ");
        scanf(" %[^\n]s", pesquisa);
        if (meuArquivo == NULL)
                printf("\n\nErro! Problema ao tentar abrir o arquivo MeuArquivo\n");
        else {
                while(!feof(meuArquivo)) {
                        fread(&end,sizeof(endereco),1,meuArquivo);
                        if (strcmp(end.nome, pesquisa) != 0) { 
                                fwrite(&end,sizeof(endereco),1,meuArquivoNovo);
                                if (feof(meuArquivo))
                                        break;
                                bandeira = 1;
                        }
        }
        if (bandeira == 0) { 
                printf("\nRegistro nao encontrado");
                system("rm exemplo2.bin");
        }
        else { 
	        remove(RegNomes.arquivo);
	        rename("exemplo2.bin",RegNomes.arquivo);
        }
        fclose(meuArquivo);
        fclose(meuArquivoNovo);
        system("clear");
    }
}

