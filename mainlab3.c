
#include <stdio.h> 
#define n 5

void bul(int a[n][n]);
void print_matrix(int a[n][n]);
int calc_matrix(int a[n][n]);

int main()

{
	int a[n][n] = {{9, 67, -65, 45, 1},
				  {12, 61, 48, -5, -1},
				  {0, 39, 0, 41, 2},
				  {36, 95, -8, -5, 0},
				  {11, 22, 71, 3, 63}};
	int res;

	printf("before sourting \n");
	print_matrix(a);

	printf("\n");
    bul(a);
	
	printf("after sourting \n");
	print_matrix(a);

	res = calc_matrix(a);
	printf("F = %d \n", res);

	getch();
}


void bul(int a[n][n])
{
	int i, k, j, c;
	int *pr;

	for (i = 0; i < n; i++)//перебираємо рядки мариці 
	{
		for (k = n - 1; k >= 0; k--)//повторення перестановок поки ел не впорядкуюься
		{
			for (j = 0; j < k; j++)//цикл для повівняння і перестановки пар значень в рядку
			{
				pr = &a[i][j];

				if (*pr < *(pr + 1))//повівняння пари значень в рядку
				{
					c = *pr;
					*pr = *(pr + 1);
					*(pr + 1) = c;
				}
			}
		}
	}
}

void print_matrix(int a[n][n])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

int calc_matrix(int a[n][n])
{
	int i, j, res = 1, sum = 0;

	for (j = 1; j < n; j++)
	{
		for (i = 0; i < j; i++)
		{
		
			sum = sum + a[i][j];
		}

		res = res * sum;
		printf("\ncol[%d] sum = %d res = %d \n", j, sum, res);
		sum = 0;
	}
}





