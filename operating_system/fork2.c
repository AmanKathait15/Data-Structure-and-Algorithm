#include<stdio.h>
#include<unistd.h> // fork() define in this

int main()
{
	fork();
	fork();
	//fork(); //2^n child process 2^n-1
	printf("aman\n");
	fflush(stdout);
}
