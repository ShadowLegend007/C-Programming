/*Write a C program to design a 5D array, store integer values in it and print them.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int dim1 = 2, dim2 = 3, dim3 = 4, dim4 = 5, dim5 = 6;
	int i, j, k, l, m;

	int *****array = (int *****)malloc(dim1 * sizeof(int ****));
	for (i = 0; i < dim1; i++)
	{
		array[i] = (int ****)malloc(dim2 * sizeof(int ***));
		for (j = 0; j < dim2; j++)
		{
			array[i][j] = (int ***)malloc(dim3 * sizeof(int **));
			for (k = 0; k < dim3; k++)
			{
				array[i][j][k] = (int **)malloc(dim4 * sizeof(int *));
				for (l = 0; l < dim4; l++)
				{
					array[i][j][k][l] = (int *)malloc(dim5 * sizeof(int));
				}
			}
		}
	}
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	for (i = 0; i < dim1; i++)
	{
		for (j = 0; j < dim2; j++)
		{
			for (k = 0; k < dim3; k++)
			{
				for (l = 0; l < dim4; l++)
				{
					for (m = 0; m < dim5; m++)
					{
						array[i][j][k][l][m] = rand() % 100;
					}
				}
			}
		}
	}
	for (i = 0; i < dim1; i++)
	{
		for (j = 0; j < dim2; j++)
		{
			for (k = 0; k < dim3; k++)
			{
				for (l = 0; l < dim4; l++)
				{
					for (m = 0; m < dim5; m++)
					{
						printf("array[%d][%d][%d][%d][%d] = %d\n", i, j, k, l, m, array[i][j][k][l][m]);
					}
				}
			}
		}
	}
	return 0;
}
