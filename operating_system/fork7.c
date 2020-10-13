#include<stdio.h>
#include<unistd.h> // fork() define in this 

int main()
{
	int a,i,n,odd=0,even=0;

	printf("enter n");
	scanf("%d",&n);

	a=fork();

	if(a>0)
	{
		for(i=0; i<=n; i+=2)
		even+=i;
			printf("%d\n",even);
	}
	if(a==0)
	{
		for(i=1; i<=n; i+=2)
		odd+=i;
			printf("%d",odd);
	}
}
