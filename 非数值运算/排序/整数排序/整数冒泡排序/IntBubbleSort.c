#include "stdio.h"
/*
两个数比较可以用中间变量替换或者位运算
*/
void ibub(int *p ,int n)
{
	int m,k,j,i,d;
	k=0;
	m=n-1;
	while(k<m)
	{
		j=m-1;
		m=0;
		for(i=k;i<=j;i++)
			if(p[i]>p[i+1])
			{
				d=p[i];
				p[i]=p[i+1];
				p[i+1]=d;
				m=i;
			}
		j=k+1;
		k=0;
		for(i=m;i>=j;i--)
			if(p[i-1]>p[i])
			{
				d=p[i];
				p[i]=p[i-1];
				p[i-1]=d;
				k=i;
			}
		
	}
}
/*
利用位运算时需注意，如果两个数相等则不能使用位运算
*/
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
		
	ibub(a,10);
	
	printf("\n排序之后：\n");
	for(count=0;count<10;count++)
	 	printf("%d\t",a[count]);
	 	
	while(1); 
} 
