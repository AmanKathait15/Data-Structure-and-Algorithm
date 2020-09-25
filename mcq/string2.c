#include<stdio.h>

int main()
{
 char str[] = "hello\0world";

 printf("%s",str);

 str[5]=' ';

 printf("\n%s",str);

 return 0;
}
