#include "stdio.h"

/*
利用位运算时需注意，如果两个数相等则不能使用位运算
*/
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
		
	QuickSort(a,0,9);
	
	printf("\n排序之后：\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
	 	
	while(1); 
} 
