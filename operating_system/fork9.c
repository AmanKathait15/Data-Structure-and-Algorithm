#include <stdio.h> 
#include <unistd.h> 
int main() 
{ 
//printf("%d",fork()); 
printf("%d ",fork() && fork()); 
//printf("%d",fork()); 

//printf("forked\n"); 
return 0; 
} 

