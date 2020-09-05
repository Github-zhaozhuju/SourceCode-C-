#include "stdio.h"

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
