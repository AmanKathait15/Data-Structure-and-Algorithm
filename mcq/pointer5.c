#include<stdio.h>

int main() 
{ 
   int a; 
   
   char *x; 
   
   x = (char *) &a; 
   
   a = 512; 		// 4 bytes 1 byte of 8 bit so in binary 00000000 00000000 00000010 00000000
   
   x[0] = 15; 		// change first 8bit to 0000 1111 
   
   x[1] = 0;

   x[2] = 0; 

   x[3] = 0;
   
   printf("%d\n",a);   
   
   return 0; 
}