#include<stdio.h>
#include<unistd.h> // fork() define in this 

int main()
{
	int a=fork(),i;

	if(a>0)
	{
		for(i=0; i<=10; i+=2)
			printf("%d\t",i);
	}
		printf("\n");
	if(a==0)
	{
		for(i=1; i<=11; i+=2)
			printf("%d\t",i);
	}
}
