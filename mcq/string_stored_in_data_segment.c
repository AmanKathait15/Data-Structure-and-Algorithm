#include<stdio.h>

char *getString() 
{ 
char *str = "GfG"; /* Stored in read only part of shared segment */

/* No problem: remains at address str after getString() returns*/
return str; 
}	 

int main() 
{ 
printf("%s", getString()); 
getchar(); 
return 0; 
} 
