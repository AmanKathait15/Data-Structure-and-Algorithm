//insertion sort

#include<stdio.h>
#define max 100

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
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

	insertionSort(a,n);

	for (int i = 0; i <n; ++i)
	{
		printf("%d ",a[i]);
	}
}