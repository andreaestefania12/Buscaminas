#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void putMinas(int rows, int lines, tipoCasilla** matrix, int nMinas);

void llenarNUm(int rows, int lines, tipoCasilla** matrix);


int main(int argc, char *argv[])
{
	int rows = atoi(argv[1])+2;
	int lines = atoi(argv[2])+2;


	tipoCasilla **matrix;

	matrix= makeMatrix(rows,lines);
    fillMatrix(rows, lines, matrix);
    putMinas(rows,lines,matrix,3);
    llenarNUm(rows, lines,matrix);
    printMatrix(rows, lines, matrix);
	return 0;
}

tipoCasilla** makeMatrix(int rows, int lines)
{
	tipoCasilla **matrix = (tipoCasilla**) malloc(rows*(sizeof(tipoCasilla*)));
	int i;
	for(i = 0; i < rows; i++)
	{
		matrix[i] = (tipoCasilla*)malloc(lines*(sizeof(tipoCasilla)));
	}

	return matrix;
}

void fillMatrix(int rows, int lines, tipoCasilla** matrix)
{
	int i, j;
	for(i = 1; i < rows-1; i++)
		for (j = 1; j < lines-1; ++j)
		{
			matrix[i][j].etiqueta = '.';
			matrix[i][j].tipo = 'C';
			matrix[i][j].nMinas = 0;
		}
}

void printMatrix(int rows, int lines, tipoCasilla** matrix)
{
	int i, j;
	for(i = 0; i < rows; i++){


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

void putMinas(int rows, int lines, tipoCasilla** matrix, int nMinas)
{
	int posFil, posCol,n;
	srand(time(NULL));
	n=0;
	while(n < nMinas)
	{
		posFil = 1+(rand()%(rows-2));
		posCol = 1+(rand()%(lines-2));
		matrix[posFil][posCol].tipo= 'M';
		n++;
	}
}


void llenarNUm(int rows, int lines, tipoCasilla** matrix)
{
	int i,j;
	
	for(i = 1; i < rows-1; i++)
	{
		for (j =  1 ; j < lines-1 ; ++j)
		{
			int minas=0;
			if(matrix[i][j].tipo != 'M')
			{
				if(matrix[i-1][j-1].tipo == 'M')
				{
					matrix[i][j].nMinas+=1;
				}

				if(matrix[i-1][j].tipo == 'M')
				{
					matrix[i][j].nMinas+=1;
				}

				if(matrix[i-1][j+1].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}

				if(matrix[i][j-1].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}

				if(matrix[i][j+1].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}

				if(matrix[i+1][j-1].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}

				if(matrix[i+1][j].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}

				if(matrix[i+1][j+1].tipo == 'M')
				{
					matrix[i][j].nMinas++;
				}
			}
		}
	}
}
		