#include<stdio.h>

int max(x,y)
int x,y;
{
	return (x>y?x:y);
}

int main()
{
	printf("%d",max(0,4));
	return 0;
}
