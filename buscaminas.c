#include <stdio.h>
#include <stdlib.h>

struct minesweeper
{
	char type;
	int box;
	int minas;
};

typedef struct minesweeper Matrix;

void makeMatrix(int rows, int lines);

void fillMatrix(int rows, int lines, int** matrix);

int main(int argc, char  *argv[])
{
	Matrix matrix;
	int rows = atoi(argv[1]);
	int lines = atoi(argv[2]);
	

	return 0;
}

void makeMatrix(int rows, int lines, int** matrix)
{
	int i;
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = (int*) malloc (lines*(sizeof(int)));
	}
}

void fillMatrix(int rows, int lines, int** matrix)
{}