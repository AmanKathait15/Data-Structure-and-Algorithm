#include<stdio.h> 
#define f(v1,v2) v1##v2 
int main() 
{ 
   int x=1,yz=2,xyz=3; 
   printf("%d", f(x,yz)); 
   return 0; 
}