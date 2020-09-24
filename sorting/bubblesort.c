//bubble sort

#include<stdio.h>
#define max 100

void bs(int a[],int n)
{
	int comp=0,swap=0;
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			comp++;
			if(a[j+1]<a[j])
			{
				swap++;
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	printf("%d\n",comp );
	printf("%d\n",swap );
}

int main()
{
	int a[max],n,i,key;

	printf("enter size : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}

	bs(a,n);

	for (int i = 0; i <n; ++i)
	{
		printf("%d ",a[i]);
	}
}