#include<bits/stdc++.h>
#define num long int
using namespace std;

void leastPrimeFactor(num a[],num n)
{
    for(num i=2; i*i<=n; i++)
    {
        if(a[i]==0)
        { 
            for(num j = i*i; j<=n; j+=i)
            {
                if(a[j]==0)
                a[j]=i;
            }
        }
    }
}

void buildsegTree(num tree[],num size)
{

}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    num t;
    cin>>t;

    while(t--)
    {
        num n,m;
        cin>>n>>m;

        num a[n+1]={0}; a[1]=1;
        
        num size = pow(2,ceil(log(n+1)/log(2)))*2;

        num tree[size+1]={0};

        for(num i=0; i<n; i++)
            tree[n+i]=a[i+1];
    }

    return 0;
}