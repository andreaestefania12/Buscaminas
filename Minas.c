#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct minesweeper
{ 
	char etiqueta;
	char type;
	int minas;	
};

typedef struct minesweeper Matrix;

Matrix** makeMatrix(int rows, int lines);

void fillMatrix(int rows, int lines, Matrix** matrix);

void putMinas(int rows, int lines, Matrix** matrix, int minas);

void fillNum(int rows, int lines, Matrix** matrix);

void uncover(int rows, int lines, Matrix** matrix);

void printMatrix(int rows, int lines, Matrix** matrix,int posRows, int posLines);





int main(int argc, char *argv[])
{
	int rows = atoi(argv[1])+2;
	int lines = atoi(argv[2])+2;
	int minas = (rows + lines)/2;


	Matrix **matrix;

	matrix= makeMatrix(rows,lines);
    fillMatrix(rows, lines, matrix);
    putMinas(rows,lines,matrix,minas);
    fillNum(rows, lines,matrix);
    printMatrix(rows, lines, matrix,0,0);
    uncover(rows,lines,matrix);

	return 0;
}

Matrix** makeMatrix(int rows, int lines)
{
	Matrix **matrix = (Matrix**) malloc(rows*(sizeof(Matrix*)));
	int i;
	for(i = 0; i < rows; i++)
	{
		matrix[i] = (Matrix*)malloc(lines*(sizeof(Matrix)));
	}

	return matrix;
}

void fillMatrix(int rows, int lines, Matrix** matrix)
{
	int i, j;
	for(i = 1; i < rows-1; i++)
		for (j = 1; j < lines-1; ++j)
		{
			matrix[i][j].etiqueta = '#';
			matrix[i][j].type = 'C';
			matrix[i][j].minas = 0;
		}
}



void putMinas(int rows, int lines, Matrix** matrix, int minas)
{
	int posRows, posLines,n;
	srand(time(NULL));
	n = 0;
	while(n < minas)
	{
		posRows = 1+(rand()%(rows-2));
		posLines = 1+(rand()%(lines-2));
		matrix[posRows][posLines].type= 'M';
		n++;
	}
}


void fillNum(int rows, int lines, Matrix** matrix)
{
	int i,j;
	
	for(i = 1; i < rows-1; i++)
	{
		for (j =  1 ; j < lines-1 ; ++j)
		{
			int minas=0;
			if(matrix[i][j].type != 'M')
			{
				if(matrix[i-1][j-1].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i-1][j].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i-1][j+1].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i][j-1].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i][j+1].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i+1][j-1].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i+1][j].type == 'M')
				{
					matrix[i][j].minas++;
				}

				if(matrix[i+1][j+1].type == 'M')
				{
					matrix[i][j].minas++;
				}
			}
		}
	}
}

void uncover(int rows, int lines, Matrix** matrix)
{
	int posRows;
	int posLines;
    while(1)
    {
    	printf("Escribir posicion fila \n");
    	scanf("%d", &posRows);
    	printf("Escribir posicion columna \n");
    	scanf("%d", &posLines);
    	printf("\n");

    	if(matrix[posRows][posLines].type == 'M')
    	{
    		printf("Perdiste :( \n");
    		break;
    	}

    	else
    	{
    		if(matrix[posRows][posLines].minas != 0)
    		{
    			printMatrix(rows,lines,matrix,posRows,posLines);
    		}
    	}

    }

}



void printMatrix(int rows, int lines, Matrix** matrix, int posRows, int posLines)
{
	int i, j;
	for(i = 1; i < rows-1; i++){


		printf(" | ");
		for (j = 1; j < lines-1; ++j)
		{
			if((i==posRows) && (j==posLines))
			{
				printf("%d  |", matrix[i][j].minas);
				matrix[i][j].etiqueta = 'x';
			}
			else if (matrix[i][j].etiqueta == 'x')
			{
				printf ("%d | ", matrix[i][j].minas);
			}

			else
			{
				printf("%c  |", matrix[i][j].etiqueta);
			}

		}
		printf("\n");		
	}

	printf("\n");
}
		