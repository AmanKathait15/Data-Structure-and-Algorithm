#include <stdio.h>
 
char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;
 
int main()
{
    printf("%s ", **++cpp);
    printf("\n%s ", *--*++cpp+3);
    printf("\n%s ", *cpp[-2]+3);
    printf("\n%s ", cpp[-1][-1]+1);
    return 0;
}
