#include<bits/stdc++.h>

using namespace std;

void square (int *x)
{
*x = (*x)++ * (*x);
}

void square (int *x, int *y)
{
*x = (--(*y)) + (*x);
}

int main ( )
{

int number = 30;

square(&number, &number);

cout << number;

return 0;
}
