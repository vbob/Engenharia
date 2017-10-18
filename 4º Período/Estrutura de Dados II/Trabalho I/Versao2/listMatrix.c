#include "listMatrix.h"

#define MAXVALUE 128

void genPPM(ListMatrix *listMatrix, char *fileName);

void main(int argc, char *argv[]) {
  // Passo como argumento o nome do arquivo qual quero gerar o mapa de colisões
  char fileName[30];
  strcpy(fileName, argv[1]);

  printf("\nTestando nome do arquivo... ");

  FILE *listaDePalavras;
  listaDePalavras = fopen(fileName, "r");
  if (listaDePalavras==NULL) {
    printf("ERRO! \nArquivo inexistente\n");
    return;
  }
   
  printf("OK \nInicializando matriz... ");
  
  ListMatrix wordList; 
  init(&wordList);

  printf("OK \nAdicionando palavras... ");
 
  char buff[40];

  for(int i = 0; buff; i++) {
    if (fgets(buff, 255, listaDePalavras) == NULL) break;
    addKey(buff, &wordList);
    }

  printf("OK \nGerando imagem... ");

  genPPM(&wordList, fileName);

  printf("OK \nFechando o arquivo... ");
  
  fclose(listaDePalavras);

  printf("OK \n\nImagem salva como '%s'\n\n", fileName); 
}

void genPPM(ListMatrix *listMatrix, char *fileName) {
	int resolutionWidth = 640; // Width of the generated image
	int resolutionHeight = 640; // Height of the generated image

	int blockSizeHeight = (int)resolutionHeight / MATRIX_HW; // Proportional Height of each Block
	int blockSizeWidth = (int)resolutionWidth / MATRIX_HW; // Proportional Width of each Block

	strcat(fileName, "-HASH3.ppm");
	FILE *image = fopen(fileName, "w");

	if (image == NULL) printf("Error opening file!\n");

	// CREATES HEADER OF PPM
	char *header[3] = {
		"P3",
		"# P3 PPM Image Format"
	};

	fprintf(image, "%s\n%s\n%d %d %i\n", header[0], header[1], resolutionWidth, resolutionHeight, MAXVALUE);

	for (int i = 0; i < MATRIX_HW; i++) { // ITERATES MLINES
		for (int j = 0; j < blockSizeHeight; j++) { // ITERATES EACH LINE PIXELS HEIGHT
			for (int k = 0; k < MATRIX_HW; k++) { // ITERATES COLUMNS
				for (int l = 0; l < blockSizeWidth; l++) { // ITERATES EACH COLUMN PIXEL WIDTH
					int block = MAXVALUE - (listMatrix->matrix[k][i]->size%MAXVALUE);
					fprintf(image, "%i %i %i ", 0, block, 30);
				}
			} fprintf(image, "\n");
		}
	}

	fclose(image);
}
