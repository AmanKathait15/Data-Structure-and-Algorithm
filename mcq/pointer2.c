#include<stdio.h>

void square (int *x, int *y)
{
*x = (*x) * --(*y);
}

int main ( )
{

int number = 30;

square(&number, &number);

printf("%d",number);

return 0;
}
