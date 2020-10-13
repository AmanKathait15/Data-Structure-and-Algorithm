#include<stdio.h>
#include<unistd.h> // fork() define in this 

int main()
{
	int a;

	if(a=fork())
	{
		printf("%d\t",a);
		fork();
	}
}
