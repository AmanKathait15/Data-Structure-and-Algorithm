#include<stdio.h>
#include<unistd.h> // fork() define in this 

int main()
{
	int a,i,j;

	a=fork();

	for(i=0,j=1; i<=10,j<=11; i+=2,j+=2)
	{
		if(a>0)
			printf("%d",i);
		else	printf("%d",j);
	}
}
