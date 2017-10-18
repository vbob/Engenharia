// Maze solver algorithm
// It creates a PPM Image of the Maze and a PPM Image of the way out
// H -> Height -> Altura // W -> Width -> Largura
// Developed by Luís Alexandre Ferreira Bueno and Vitor Bruno de Oliveira Barth
// Em 24/08/2016

#include "xyQueue.h"
#include <stdlib.h>
#include <string.h>

// Width of the maze
#define SIZEW 10
// Height of the maze
#define SIZEH 10

void writePPM(int maze[SIZEW][SIZEH], char *name);
void solveMaze(int maze[SIZEW][SIZEH], int startPosition[2], int finalPosition[2]);

int main() {
	int maze[SIZEW][SIZEH] = {
		  	{1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
		  	{1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
			{1, 0, 1, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
			{1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
			{0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
			{1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
			{1, 1, 0, 1, 0, 1, 1, 1, 0, 1}
	}; // 1 stands for WAY and 0 stands for BLOCKAGE

	writePPM(maze, "NONSOLVED.ppm");

	int startPosition[2] = {0,0};
	int finalPosition[2] = {(SIZEW-1),(SIZEH-1)};

	solveMaze(maze, startPosition, finalPosition);
}

void writePPM(int maze[SIZEW][SIZEH], char *name) {
	int resolutionWidth = 800; // Width of the generated image
	int resolutionHeight = 800; // Height of the generated image

	int blockSizeHeight = (int) resolutionHeight/SIZEH; // Proportional Height of each Block
	int blockSizeWidth = (int) resolutionWidth/SIZEW; // Proportional Width of each Block

	FILE *image = fopen(name, "w");

	if (image == NULL)
		printf("Error opening file!\n");

	// CREATES HEADER OF PPM
	char *header[2] = {
		"P3",
		"# P3 PPM Image Format",
	};

	fprintf(image, "%s\n%s\n%d %d 1\n", header[0], header[1], resolutionWidth, resolutionHeight);

	for (int i = 0; i < SIZEH; i++) { // ITERATES MAZE LINES
		for (int j = 0; j < blockSizeHeight; j++) { // ITERATES EACH LINE PIXELS HEIGHT
			for (int k = 0; k < SIZEW; k++) { // ITERATES MAZE COLUMNS
				for (int l = 0; l < blockSizeWidth; l++) { // ITERATES EACH COLUMN PIXEL WIDTH
					if (maze[i][k] == 0)
						fprintf(image, "0 0 0  "); // PAINT WALL
					else if (maze[i][k] == -1 && (j > blockSizeHeight/3 && j < 2*blockSizeHeight/3 || l > blockSizeHeight/3 && l < 2*blockSizeHeight/3))
						fprintf(image, "1 0 0  "); // PAINT CROSS IN WAY OUT
					else
						fprintf(image, "1 1 1  "); // PAINT WAY
				}
			}
		fprintf(image, "\n");
		}
	}

	fclose(image);
}

void solveMaze(int maze[SIZEW][SIZEH], int startPosition[2], int finalPosition[2]) {
	xyQueue queue;
	init(&queue,1);
	enqueue(&queue,(coordXY){startPosition[1],startPosition[0]});

	int wayOut=0;

	maze[startPosition[1]][startPosition[0]] = 2;

	// USED TO FIND WAY OUT
	while (!isEmpty(&queue) && !wayOut) {
		coordXY pos = dequeue(&queue);

		int way = maze[pos.x][pos.y];

		if (pos.x==finalPosition[1] && pos.y==finalPosition[0]) {
			wayOut = 1;
		} 

		else {
			if (pos.x < SIZEW-1 && maze[pos.x+1][pos.y]==1) { 
				enqueue(&queue,(coordXY){pos.x+1,pos.y}); 
				maze[pos.x+1][pos.y]=way+1;
			}

			if (pos.y < SIZEH-1 && maze[pos.x][pos.y+1]==1) { 
				enqueue(&queue,(coordXY){pos.x,pos.y+1}); 
				maze[pos.x][pos.y+1]=way+1;
			}

			if (pos.y > 0 && maze[pos.x][pos.y-1]==1) { 
				enqueue(&queue,(coordXY){pos.x,pos.y-1}); 		  
				maze[pos.x][pos.y-1]=way+1;
			}
		
			if (pos.x > 0 && maze[pos.x-1][pos.y]==1) { 
				enqueue(&queue,(coordXY){pos.x-1,pos.y});
				maze[pos.x-1][pos.y]=way+1;}
		}
	}

	if (wayOut) {
		empty(&queue); // USED TO EMPTY THE QUEUE

		enqueue(&queue,(coordXY){finalPosition[1],finalPosition[0]});
		wayOut = 0;

		// IF THERE'S A WAY OUT, GO BACK TO FIND THE SHORTEST
		while (!wayOut) {
			coordXY pos = dequeue(&queue);

			if (pos.x < SIZEW-1 && maze[pos.x+1][pos.y]==maze[pos.x][pos.y]-1)
				enqueue(&queue,(coordXY){pos.x+1,pos.y});

			if (pos.y < SIZEH-1 && maze[pos.x][pos.y+1]==maze[pos.x][pos.y]-1) 
				enqueue(&queue,(coordXY){pos.x,pos.y+1}); 

			if (pos.y > 0 && maze[pos.x][pos.y-1]==maze[pos.x][pos.y]-1) 
				enqueue(&queue,(coordXY){pos.x,pos.y-1}); 		  

			if (pos.x > 0 && maze[pos.x-1][pos.y]==maze[pos.x][pos.y]-1)
				enqueue(&queue,(coordXY){pos.x-1,pos.y});

			if (pos.x==startPosition[1] && pos.y==startPosition[0]) {
				wayOut = 1;
				maze[pos.x][pos.y]=-1;
			}

			maze[pos.x][pos.y]=-1;
		}

		writePPM(maze, "SOLVED.ppm");
	} 

	else 
		printf("\n\nNO WAY FROM (%d, %d) TO (%d, %d)\n\n", startPosition[0], startPosition[1], finalPosition[0], finalPosition[1]);
}
