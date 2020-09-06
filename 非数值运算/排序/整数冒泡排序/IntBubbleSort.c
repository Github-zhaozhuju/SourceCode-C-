#include "stdio.h"

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


void main()
{
	int count=0;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	
	printf("原始数组：\n");
	for(count=0;count<10;count++)
		printf("%d\t",a[count]);
		
	RubbleSort(a,10);
	
	printf("\n排序之后：\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
} 
