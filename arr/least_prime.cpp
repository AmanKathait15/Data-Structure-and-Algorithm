#include<bits/stdc++.h>
using namespace std;
#define num long int

vector<num> v({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199});

num leasPrimeDiv(num n)
{
    for(num i=0; i<v.size(); i++)
        if(n%v[i]==0) return v[i];

    return n;
}

num query(num a[],num l,num r)
{
    num res = 1;

    for(num i=l; i<=r; i++)
    {
        res = max(res,leasPrimeDiv(a[i]));
    }

    return res;
}

void update(num a[],num l,num r)
{
    for(num i=l; i<=r; i++)
        a[i]/= leasPrimeDiv(a[i]);
}

void display(num a[],num n)
{
    for(num i=0; i<n; i++)
    {
        printf("%ld ",a[i]);
    }   printf("\n");
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    num t; cin>>t;

    while(t--)
    {
        num n,q; cin>>n>>q; num a[n];

        for(num i=0; i<n; i++) cin>>a[i];

        while(q--)
        {
            num x,l,r;  cin>>x>>l>>r;

            if(x==1)    cout<<query(a,l-1,r-1)<<" "; // O(n)
            else
            {
                update(a,l-1,r-1); //display(a,n);
            }
        }

        cout<<"\n";
    }

    return 0;
}