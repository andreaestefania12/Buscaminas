#include <stdio.h>
#include <stdlib.h>

int** makeMatrix(int rows, int lines);

int main(int argc, char  *argv[])
{
	int rows = atoi(argv[1]);
	int lines = atoi(argv[2]);
	int** matrix= (int**) malloc(rows*(sizeof(int*)));
	return 0;
}

int** makeMatrix(int rows, int lines, int** matrix)
{
	int i;
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = (int*) malloc (lines*(sizeof(int)));
	}

	return matrix;
}