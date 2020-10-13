#include<stdio.h>
#include<unistd.h> // fork() define in this 

int main()
{
	int a,i,n;

	printf("enter n");
	scanf("%d",&n);

	a=fork();

	if(a>0)
	{
		for(i=0; i<=n; i+=2)
			printf("%d\t",i);
	}
		printf("\n");
	if(a==0)
	{
		for(i=1; i<=n; i+=2)
			printf("%d\t",i);
	}
}
