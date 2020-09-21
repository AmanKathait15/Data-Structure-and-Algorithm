#include<bits/stdc++.h>
using namespace std;
#define num int

num find_sum(num s[],num n)
{
    num l,r; cin>>l>>r;

    return s[r+1]-s[l];
}

void update(num a[],num s[],num n)
{
    num i,val,sum=0; cin>>i>>val;

    a[i] = val;

    for(num i=0; i<n; i++)
    {
        sum+=a[i]; s[i+1]=sum;
    }
}

int main()
{
    num t; cin>>t;

    while(t--)
    {
        num n,q,sum=0; cin>>n>>q; num a[n],s[n+1]={0};

        for(num i=0; i<n; i++)
        {
            cin>>a[i]; sum+=a[i]; s[i+1]=sum;
        }

        while(q--)
        {
            num x,l,r; cin>>x;

            if(x==0)    cout<<find_sum(s,n)<<"\n"; // O(1)
            else        update(a,s,n);                // O(n)
        }
    }
    
    return 0;
}