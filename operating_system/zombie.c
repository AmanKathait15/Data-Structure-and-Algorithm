#include <stdio.h> 
#include <unistd.h> 
#include<sys/wait.h>
int main() 
{
	pid_t p = fork();

	if(p>0)
	{
		printf("parent process pid = %d",getpid);
		//wait(NULL);
		//sleep(50);
	}
	else
	{
		printf("child process pid = %d parent pid = %d",getpid(),getppid());
	} 
return 0; 
} 

