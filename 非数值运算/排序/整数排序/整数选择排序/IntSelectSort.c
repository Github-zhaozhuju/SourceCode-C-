#include "stdio.h"

/*
利用位运算时需注意，如果两个数相等则不能使用位运算
*/
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

/*
冒泡排序时间复杂度为 O(n2)
*/
void main()
{
	int count=0;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	
	printf("原始数组：\n");
	for(count=0;count<10;count++)
		printf("%d\t",a[count]);
		
	SelectSort(a,10);
	
	printf("\n排序之后：\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
	 	
	while(1); 
} 
