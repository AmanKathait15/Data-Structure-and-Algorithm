#include <stdio.h> 
#include <unistd.h> 
int main() 
{
	int p = fork();

	if(p>0)
	{
		printf("parent process pid = %d",getpid());
	}
	else
	{
		//sleep(50);
		printf("\nchild process pid = %d , parent pid = %d",getpid(),getppid());
	} 
return 0; 
} 

