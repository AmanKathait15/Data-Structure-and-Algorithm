#include<bits/stdc++.h>

using namespace std;

int lru(int capacity, int a[])
{
  int b[capacity]={0};

  for(int i=0; i<capacity; i++)
    b[i]=a[i];
  return 0;
}

int main()
{
  int n,a[max]={0};
  printf("enter capacity : ");
  scanf("%d",&n);
  string str;
  printf("enter reference string seprated by comma : ");
  cin>>str;

  for(int i=0; i<str.length(); i++)
  {
    if(str[i]==',')
      continue;
    else
    {
      a[k++]=str
    }
  }

  return 0;
}