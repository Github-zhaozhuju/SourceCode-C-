#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
#define LEN	100000
 
 
//—°‘Ò≈≈–Ú
void SelectSort(int array[], size_t size)
{
	size_t i, j;
	for (i=0; i<size-1; i++)
		for (j=size-1; j>i; j--)
			if (array[i] > array[j])
			{
				array[i] = array[i] ^ array[j];
				array[j] = array[i] ^ array[j];
				array[i] = array[i] ^ array[j];
			}
}
 
 
//√∞≈›≈≈–Ú
void RubbleSort(int array[], size_t size)
{
	size_t i, j;
	for (i=0; i<size-1; i++)
		for (j=0; j<size-1-i; j++)
			if (array[j] > array[j+1])
			{
				array[j]   = array[j] ^ array[j+1];
				array[j+1] = array[j] ^ array[j+1];
				array[j]   = array[j] ^ array[j+1];
			}
}
 
//øÏÀŸ≈≈–Ú
void QuickSort(int array[], int left, int right)
{
	if (left >= right)
		return;
	int i, j;
	int tmp;
	i = left;
	j = right;
 
	while (i < j)
	{
		while (array[j]>=array[left] && i<j)
			j--;
		while (array[i]<=array[left] && i<j)
			i++;
 
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
	
	tmp = array[left];
	array[left] = array[i];
	array[i] = tmp;
 
	QuickSort(array, left, i-1);
	QuickSort(array, i+1, right);
}
 
int main(int argc, const char *argv[])
{
	int i;
	clock_t start, end;
	int *a, *b, *c;
	a = (int *)malloc(sizeof(int)*LEN);
	if (a == NULL)
	{
		perror("Create a failed");
		return EXIT_FAILURE;
	}
	
	b = (int *)malloc(sizeof(int)*LEN);
	if (b == NULL)
	{
		perror("Create b failed");
		return EXIT_FAILURE;
	}
	c = (int *)malloc(sizeof(int)*LEN);
	if (c == NULL)
	{
		perror("Create c failed");
		return EXIT_FAILURE;
	}
 
	srand(time(NULL));
	for (i = 0; i<LEN; i++)
	{
		a[i] = rand() % 10000;
		c[i] = b[i] = a[i];
	}
 
	printf("a[100] = %d b[100] = %d c[100] = %d\n", a[100], b[100], c[100]);
 
	start = clock();
	SelectSort(a, LEN);
	end = clock();
	printf("SelectSort Time = %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
 
	start = clock();
	RubbleSort(b, LEN);
	end = clock();
	printf("RubbleSort Time = %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
 
	start = clock();
	QuickSort(c, 0, LEN-1);
	end = clock();
	printf("QuickSort Time = %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
 
	printf("a[100] = %d b[100] = %d c[100] = %d\n", a[100], b[100], c[100]);
	
	return 0;
}
