#include<stdio.h>

void fun(int arr[])
{
  int i;
  
  int arr_size = sizeof(arr)/sizeof(arr[0]); // 8/4 arr is pointer

  printf("array size at main = %d\n",arr_size);
  
  for (i = 0; i < arr_size; i++)

        printf("%d ", arr[i]);
}
 
int main()
{
  int i;
  
  int arr[4] = {10, 20 ,30, 40};

  int arr_size = sizeof(arr)/sizeof(arr[0]); // 4*4/4

  printf("array size at main = %d\n",arr_size);
  
  fun(arr);
  
  return 0;
}