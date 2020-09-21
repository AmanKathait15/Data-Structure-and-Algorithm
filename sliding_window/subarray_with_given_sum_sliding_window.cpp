//brute force approcah

#include<bits/stdc++.h>
using namespace std;
#define num long int

void sliding_window(vector<num> v,num n,num k)
{
    num sum=0,i=0,j=0;

    if(sum==k)
    {
        printf("%ld %ld",j+1,i+1); return;
    }

    while(i<=n)
    {
        if(sum<k) sum+=v[i++];
        else           sum-=v[j++];

        if(sum==k)
        {
            printf("%ld %ld",j+1,i); return;
        }
    }

    printf("-1\n");
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        num n,k,sum=0; cin>>n>>k;

        vector<num> v(n);

        for(num i=0; i<n; i++) cin>>v[i];

        sliding_window(v,n,k);
    }

    return 0;
}