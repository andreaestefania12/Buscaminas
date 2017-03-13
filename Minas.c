#include <stdio.h>
#include <stdlib.h>

struct Casilla
{ 
	char etiqueta;
	char tipo;
	int nMinas;	
};

typedef struct Casilla tipoCasilla;

tipoCasilla** makeMatrix(int rows, int lines);

void fillMatrix(int rows, int lines, tipoCasilla** matrix);

void printMatrix(int rows, int lines, tipoCasilla** matrix);

int main(int argc, char *argv[])
{
	int rows = atoi(argv[1]);
	int lines = atoi(argv[2]);

	tipoCasilla **matrix;

	matrix= makeMatrix(rows,lines);
    fillMatrix(rows, lines, matrix);
    printMatrix(rows, lines, matrix);
	return 0;
}

tipoCasilla** makeMatrix(int rows, int lines)
{
	tipoCasilla **matrix = (tipoCasilla**) malloc(rows*(sizeof(tipoCasilla*)));
	int i;
	for(i=0; i< rows; i++)
	{
		matrix[i] = (tipoCasilla*)malloc(lines*(sizeof(tipoCasilla)));
	}

	return matrix;
}

void fillMatrix(int rows, int lines, tipoCasilla** matrix)
{
	int i, j;
	for(i=0; i<rows; i++)
		for (j = 0; j < lines; ++j)
		{
			matrix[i][j].etiqueta = '.';
			matrix[i][j].tipo = 'C';
			matrix[i][j].nMinas = 0;
		}
}

void printMatrix(int rows, int lines, tipoCasilla** matrix)
{
	int i, j;
	for(i=0; i<rows; i++){


		printf(" | ");
		for (j = 0; j < lines; ++j)
		{
			printf ("%c ", matrix[i][j].etiqueta);
			printf ("%c ",matrix[i][j].tipo );
			printf ("%d | ",matrix[i][j].nMinas);
		}
		printf("\n");
		
	}
}