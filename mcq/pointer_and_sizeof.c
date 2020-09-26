#include <stdio.h>
 
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %lu ", sizeof(arri));
    printf("sizeof ptri = %lu ", sizeof(ptri));
 
    printf("sizeof arrc[] = %lu ", sizeof(arrc));
    printf("sizeof ptrc = %lu ", sizeof(ptrc));
 
    return 0;
}