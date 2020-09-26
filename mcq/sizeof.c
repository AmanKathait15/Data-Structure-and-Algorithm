#include <stdio.h>
int fun()
{
    puts(" Hello ");
    return 10;
}
 
int main()
{
    printf("%d", sizeof(fun()));
    return 0;
}
