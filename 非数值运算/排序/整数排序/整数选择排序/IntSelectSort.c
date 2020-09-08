#include "stdio.h"

/*
����λ����ʱ��ע�⣬����������������ʹ��λ����
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
ð������ʱ�临�Ӷ�Ϊ O(n2)
*/
void main()
{
	int count=0;
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	
	printf("ԭʼ���飺\n");
	for(count=0;count<10;count++)
		printf("%d\t",a[count]);
		
	SelectSort(a,10);
	
	printf("\n����֮��\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
	 	
	while(1); 
} 
