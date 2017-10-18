#ifndef SCOLLMAP_H
#define SCOLLMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 30 // MAXIMUM WORD LENGHT
#define MAPSIZE   32 // SIZE OF COLLISIONTABLE

typedef struct Node {
    struct Node *nextWord;
    char   word[WORD_SIZE];
} Node;

typedef struct WordList {
    Node *firstWord;
	Node *lastWord;
    int  size;
} WordList;

typedef struct CollisionMap {
	WordList  *wordListTable[MAPSIZE][MAPSIZE];
    int       collisionTable[MAPSIZE][MAPSIZE];
} CollisionMap;

void initWordList		(WordList *words);
void initCollisionMap   (CollisionMap* collisionMap);
void add                (CollisionMap *collisionMap, char word[WORD_SIZE]);
int  genHash            (char word[WORD_SIZE]);
void printCollisionMap  (int colisionTable[MAPSIZE][MAPSIZE]);

void initWordList		(WordList *words) {
	words->firstWord = words->lastWord = NULL;
	words->size=0;
}

void initCollisionMap   (CollisionMap *collisionMap) {
    WordList cache[MAPSIZE][MAPSIZE];

	for (int i = 0; i < MAPSIZE; i++) {
        for (int j = 0; j < MAPSIZE; j++) {
			collisionMap->wordListTable[i][j] = &cache[i][j]; 
            initWordList(collisionMap->wordListTable[i][j]);
		}
    }

	for (int i = 0; i < MAPSIZE; i++) 
		for (int j = 0; j < MAPSIZE; j++)
			collisionMap->collisionTable[i][j]=0;
}

void add                (CollisionMap *collisionMap, char word[WORD_SIZE]) {
	int position = genHash(word);
	int positionY = (int) (position/MAPSIZE);
	int positionX = (position-((positionY)*MAPSIZE));

	Node *cacheNode = (Node*) malloc(sizeof(Node));
	strcpy(cacheNode->word, word);
	
	if (collisionMap->wordListTable[positionX][positionY]->size == 0)
		collisionMap->wordListTable[positionX][positionY]->firstWord = collisionMap->wordListTable[positionX][positionY]->lastWord = cacheNode;
	
	else  {
		//collisionMap->wordListTable[positionX][positionY]->lastWord->nextWord = cacheNode;
		collisionMap->wordListTable[positionX][positionY]->lastWord = cacheNode;
	}

	collisionMap->collisionTable[positionX][positionY]++;

}

int  genHash            (char word[WORD_SIZE]) {
	int acumulator = 0;

	for (int i = 0; i < WORD_SIZE; i++)
		acumulator += word[i]*(i+1)*3;

	return abs(acumulator%(MAPSIZE*MAPSIZE));
}

void printCollisionMap  (int collisionTable[MAPSIZE][MAPSIZE]) {
	int resolutionWidth = 640; // Width of the generated image
	int resolutionHeight = 640; // Height of the generated image

	int blockSizeHeight = (int) resolutionHeight/MAPSIZE; // Proportional Height of each Block
	int blockSizeWidth = (int) resolutionWidth/MAPSIZE; // Proportional Width of each Block

	FILE *image = fopen("collisionMap.ppm", "w");

	if (image == NULL)
		printf("Error opening file!\n");

	// CREATES HEADER OF PPM
	char *header[3] = {
		"P2",
		"# P2 PPM Image Format"
	};

	fprintf(image, "%s\n%s\n%d %d 20\n", header[0], header[1], resolutionWidth, resolutionHeight);

	for (int i = 0; i < MAPSIZE; i++) { // ITERATES MLINES
		for (int j = 0; j < blockSizeHeight; j++) { // ITERATES EACH LINE PIXELS HEIGHT
			for (int k = 0; k < MAPSIZE; k++) { // ITERATES COLUMNS
				for (int l = 0; l < blockSizeWidth; l++) { // ITERATES EACH COLUMN PIXEL WIDTH
                    fprintf(image, "%i ", (int) (collisionTable[k][i]/15));
				}
			}
		fprintf(image, "\n");
		}
	}

	fclose(image);
}

#endif


