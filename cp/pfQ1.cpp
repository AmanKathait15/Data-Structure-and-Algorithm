#include<bits/stdc++.h>
using namespace std ;
#define num unsigned int

bool prime(num x)
{
    for(num i=2; i<=x/2; i++)
    {
        if(x%i==0)  return 0;
    }
    return 1;
}

int main()
{
    num n;
    cin>>n;
    
    for(num i=2; i<=n; i++)
    if(prime(i))
    cout<<i<<",";
    return 0;
}