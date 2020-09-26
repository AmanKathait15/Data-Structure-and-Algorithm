#include <stdio.h>

int fun(int ) ;
 
int main()
{
    int (*ptr)(int ) = fun;
    (*ptr)(3);
    return 0;
}
 
int fun(int n)
{
  for(;n > 0; n--)
    printf("GeeksQuiz ");
  return 0;
}