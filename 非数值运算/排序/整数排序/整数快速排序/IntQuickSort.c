#include "stdio.h"

/*
����λ����ʱ��ע�⣬����������������ʹ��λ����
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
ð������ʱ�临�Ӷ�Ϊ O(n2)
*/
void main()
{
	int count=0;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	
	printf("ԭʼ���飺\n");
	for(count=0;count<10;count++)
		printf("%d\t",a[count]);
		
	QuickSort(a,0,9);
	
	printf("\n����֮��\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
	 	
	while(1); 
} 
