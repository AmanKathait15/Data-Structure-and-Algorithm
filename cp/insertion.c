#include<stdio.h>
#include<stdlib.h>
#define num int

int main()
{
	num a[10] = {1,4,2,5,6,1,7,8,9,10};
	
	for(num i=1; i<10; i++)
	{
		num tmp = a[i],j=i-1; 	
		while(j>0 && a[j]>tmp)
		{
			a[j] = a[j-1]; j--;
		}
		a[j] = tmp;
	}
	
	for(num i=0; i<10; i++)
	printf("%d ",a[i]);

	return 0;
}
