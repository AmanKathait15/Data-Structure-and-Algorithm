# include <stdio.h>
#include<string.h>
 
int main()
{
   char str1[] = "GeeksQuiz";
   char str2[] = {'G', '\0', 'e', 'k', 's', 'Q', 'u', 'i', 'z'};
   int n1 = strlen(str1);
   int n2 = strlen(str2);
   printf("n1 = %d, n2 = %d", n1, n2);
   return 0;
}
