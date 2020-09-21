#include<bits/stdc++.h>
using namespace std;
#define num int

num find_sum(num a[],num n)
{
    num l,r,sum=0; cin>>l>>r;

    for(num i=l; i<r+1; i++)    sum+=a[i];

    return sum;
}

void update(num a[],num n)
{
    num i,val; cin>>i>>val;

    a[i] = val;
}

int main()
{
    num t; cin>>t;

    while(t--)
    {
        num n,q; cin>>n>>q; num a[n];

        for(num i=0; i<n; i++) cin>>a[i];

        while(q--)
        {
            num x,l,r; cout<<"0: insert 1: update : ";
            cin>>x;

            if(x==0)    cout<<find_sum(a,n)<<"\n"; // O(n)
            else        update(a,n);                // O(1)
        }
    }

    return 0;
}