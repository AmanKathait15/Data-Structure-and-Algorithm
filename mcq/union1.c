#include<stdio.h>
union test
{
    int x;
    int y;
};
 
int main()
{
    union test t; t.x=5;
    printf("%d", t.y);
    return 0;
}
