#include "mapaColisoes.h"

void main() {
    CollisionMap collisionMap;

    initCollisionMap(&collisionMap);

    FILE *listaDePalavras;
    listaDePalavras = fopen("palavras-ingles.txt", "r");

    char buff[255];

    fscanf(listaDePalavras, "%s", buff);
    add(&collisionMap, buff);

    for(int i = 0; buff; i++) {
        if (fgets(buff,255, listaDePalavras) == NULL) break;
        int position = genHash(buff);
	    int positionY = (int) (position/32);
	    int positionX = (position-((positionY)*32));
        for (int j = 0; buff[j]; j++)
            if (buff[j] == '\n') buff[j] = '\0';
        

        //printf("PALAVRA = %s. KEY = %i. Adicionando na posicao %i %i\n", buff, position, positionX, positionY);
        add(&collisionMap, buff);
    }

    printCollisionMap(collisionMap.collisionTable);
}


