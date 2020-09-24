//bubble sort

#include<stdio.h>
#define max 100

void ss(int a[], int n)  
{  
    int i, j, min_idx;  
 
    for (i = 0; i < n-1; i++)  
    {   
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
   
        swap(&arr[min_idx], &arr[i]);  
    }  
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