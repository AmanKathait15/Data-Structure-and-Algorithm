#include<stdio.h>

int * g (void) 
{ 
  int x= 10; 
  return (&x); 
} 

int main()
{
 printf("%d",*(g()));
 return 0;
}
