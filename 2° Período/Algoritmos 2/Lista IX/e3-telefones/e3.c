#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int telefone;
        char cidade[100];
        int tempo;
} chamada;

void cadastrar(char arquivo[100]);
void listar(char arquivo[100]);
void trocarArquivo(char arquivo[100]);
void comparar();

//struct
chamada chmd;

void main(){
    char arquivo[100];
    int escolha;
    trocarArquivo(arquivo);
    do{
    	system("clear");
    	printf("\n===========================");
    	printf("\nArquivo em uso: %s", arquivo);
        printf("\n===========================");
        printf("\n1- Cadastrar chamada");
        printf("\n2- Listar chamadas");
        printf("\n3- Comparar telefone e cidade de dois arquivos");
        printf("\n4- Trocar de arquivo");
        printf("\n5- Finalizar");
        printf("\n===========================");
        printf("\nInsira a opção desejada: ");
        scanf("%i", &escolha);
        switch(escolha){
            case 1: system("clear");
            	    cadastrar(arquivo);
                    printf("\nAperte Enter para retornar ao menu");
                    getchar();
                    getchar();
            	    break;
            case 2: system("clear");
            	    listar(arquivo);
                    printf("\nAperte Enter para retornar ao menu");
                    getchar();
                    getchar();
                    break;
            case 3: system("clear");
            	    comparar();
                    printf("\nAperte Enter para retornar ao menu");
                    getchar();
                    getchar();
                    break;
            case 4: system("clear");
            	    trocarArquivo(arquivo);
                    printf("\nAperte Enter para retornar ao menu");
                    getchar();
                    getchar();
                    break;
            case 5: system("clear");   	
        }
    } while(escolha != 5);
}

void cadastrar(char arquivo[100]) {
	FILE *meuArquivo;
	int hora, min, seg;
	meuArquivo = fopen(arquivo, "a");
	if(meuArquivo == NULL)
		printf("\nErro ao tentar abrir o arquivo\n");
	else{
		printf("\nInsira o numero do telefone: ");
		scanf("%i", &chmd.telefone);
		printf("\nInsira o nome da cidade: ");
		scanf(" %[^\n]s", chmd.cidade);
		printf("\nInsira o tempo de ligação [hh mm ss]: ");
		scanf("%i %i %i", &hora, &min, &seg);
		chmd.tempo = (hora*3600)+(min*60)+seg;
		fprintf(meuArquivo, "%i,%s,%i,\n", chmd.telefone, chmd.cidade, chmd.tempo);
	}
	fclose(meuArquivo);	
}

void listar(char arquivo[100]) {
	char linha[100], sep[2] = ",", *str;
	FILE *meuArquivo;
	meuArquivo = fopen(arquivo, "r");
	int bandeira = 0, hora, min, seg;
	
	if(meuArquivo == NULL)
		printf("\nErro ao tentar abrir o arquivo\n");
	else{
		do{
			str = fgets(linha, 100, meuArquivo);
			if(str != NULL){
				if(bandeira == 0)
					printf("\n%-10s %-15s %-15s\n", "TELEFONE", "CIDADE", "TEMPO");
					bandeira = 1;
				chmd.telefone = atoi(strtok(str, sep));
				strcpy(chmd.cidade, strtok(NULL, sep));
				chmd.tempo = atoi(strtok(NULL, sep));
				seg = chmd.tempo%60;
				min = ((chmd.tempo - seg)%3600)/60;
				hora = ((chmd.tempo - seg)- min*60)/3600;
				
				printf("%-10i %-15s %ihrs %imin %iseg\n", chmd.telefone, chmd.cidade, hora, min, seg);
			}
		}while(str != NULL);
	fclose(meuArquivo);		
	}
}

void trocarArquivo(char arquivo[100]) {
	FILE *meuArquivo;
	printf("Insira o nome do arquivo: ");
	scanf(" %[^\n]s", arquivo);
}

void comparar() {
	int i= 0, tam1, tam2;
	char arq1[100], arq2[100], linha[100], *str1, *str2, sep[2] = ",";
	chamada vetor1[100];
	chamada vetor2[100];
	printf("\nInsira o nome do primeiro arquivo: ");
	scanf(" %[^\n]s", arq1);
	printf("\nInsira o nome do segundo arquivo: ");
	scanf(" %[^\n]s", arq2);
	FILE *Arquivo1;
	FILE *Arquivo2;
	Arquivo1 = fopen(arq1, "r");
	Arquivo2 = fopen(arq2, "r");
	
	if(Arquivo1 == NULL || Arquivo2 == NULL)
		printf("\nErro ao tentar abrir o arquivo\n");
	else{
		do{
			str1 = fgets(linha, 100, Arquivo1);
			if(str1 != NULL){
				vetor1[i].telefone = atoi(strtok(str1, sep));
				strcpy(vetor1[i].cidade, strtok(NULL, sep));
				vetor1[i].tempo = atoi(strtok(NULL, sep));
			}
			i++;
		}while(str1!=NULL);
		tam1 = i;
		i = 0;
		do{
			str2 = fgets(linha, 100, Arquivo2);
			if(str2 != NULL){
				vetor2[i].telefone = atoi(strtok(str2, sep));
				strcpy(vetor2[i].cidade, strtok(NULL, sep));
				vetor2[i].tempo = atoi(strtok(NULL, sep));
			}
			i++;
		}while(str2!=NULL);
		tam2 = i;
						
	}
	i=0;
	int j = 0;
	while (i<tam1) {
		j = 0;
		while (j<tam2) {
			if (vetor1[i].telefone == vetor2[j].telefone && strcmp(vetor1[i].cidade, vetor2[j].cidade) == 0){
				vetor1[i].tempo += vetor2[j].tempo;
				vetor2[j].tempo = 0;
			}	
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < tam1) {
		j = 0;
		while (j < tam1) {
			if (vetor1[i].telefone == vetor1[j].telefone && i != j && strcmp(vetor1[i].cidade, vetor1[j].cidade) == 0){
				vetor1[i].tempo += vetor1[j].tempo;
				vetor1[j].tempo = 0;
			}
			j++;	
		}
		i++;
	}
	tam1 = i;
	tam2 = j;
	
	fclose(Arquivo1);
	fclose(Arquivo2);
	remove(arq1);
	remove(arq2);
	Arquivo1 = fopen(arq1, "a");
	Arquivo2 = fopen(arq2, "a");	
	
	i=0;
	j=0;
	while(i != tam1){
		if(vetor1[i].tempo != 0)
			fprintf(Arquivo1, "%i,%s,%i\n", vetor1[i].telefone, vetor1[i].cidade, vetor1[i].tempo);
		i++;
	}
	while(j != tam2){
		if(vetor2[j].telefone != 0)
			fprintf(Arquivo2, "%i,%s,%i\n", vetor2[j].telefone, vetor2[j].cidade, vetor2[j].tempo);
		j++;
	}
	fclose(Arquivo1);
	fclose(Arquivo2);	 
}
