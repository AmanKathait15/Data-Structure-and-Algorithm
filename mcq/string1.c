#include<stdio.h>

int main()
{
 char *ptr = "hello\0world";

 printf("%s",ptr);

 ptr = "world";

 printf("%s",ptr);

 return 0;
}
