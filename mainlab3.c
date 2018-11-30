//hello
#include <stdio.h> 
#define ROW_COLUMN_SIZE 5

void buble_sort(int array[][ROW_COLUMN_SIZE])
{
	int row, short_index, column, temporary_place;
	int *pointer;

	for (row = 0; row < ROW_COLUMN_SIZE; row++)
	{
		for (short_index = ROW_COLUMN_SIZE - 1; short_index >= 0; short_index--)
		{
			for (column = 0; column < short_index; column++)
			{
				pointer = &array[row][column];

				if (*pointer < *(pointer + 1))
				{
					temporary_place = *pointer;
					*pointer = *(pointer + 1);
					*(pointer + 1) = temporary_place;
				}
			}
		}
	}
}

void print_matrix(int array[][ROW_COLUMN_SIZE])
{
	int row, column;
	for (row = 0; row < ROW_COLUMN_SIZE; row++)
	{
		for (column = 0; column < ROW_COLUMN_SIZE; column++)
		{
			printf("%5d", array[row][column]);
		}
		printf("\n");
	}
}

int calc_matrix(int array[][ROW_COLUMN_SIZE])
{
	int row, column, result = 1, sum = 0;

	for (column = 1; column < ROW_COLUMN_SIZE; column++)
	{
		for (row = 0; row < column; row++)
		{
			printf("%5d", array[row][column]);
			sum = sum + array[row][column];
		}

		result = result * sum;
		printf(" sum = %d result = %d \n", sum, result);
		sum = 0;
	}

	return result;
}

int main()
{
	int matrix[ROW_COLUMN_SIZE][ROW_COLUMN_SIZE] = { {9, 67, -65, 45, 1},
				  {12, 61, 48, -5, -1},
				  {0, 39, 0, 41, 2},
				  {36, 95, -8, -5, 0},
				  {11, 22, 71, 3, 63} };
	int result;

	printf("before sourting \n");
	print_matrix(matrix);

	printf("\n");
	buble_sort(matrix);

	printf("after sourting \n");
	print_matrix(matrix);

	result = calc_matrix(matrix);
	printf("Matrix = %d \n", result);

	getch();
}





