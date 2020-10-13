#include<stdio.h>
#include<unistd.h> // fork() define in this

// what fork return ? 

int main()
{
	int a=fork();

	if(a>0)
		printf("parent process id=%d\n",a);
	else
		printf("child process id=%d\n",a);
}
