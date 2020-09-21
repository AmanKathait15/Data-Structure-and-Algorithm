#include<bits/stdc++.h>
using namespace std;
#define num long int

num leasPrimeDiv(num n)
{
    if(n%2==0) return 2;

    for(num i=3; i*i<=n; i+=2)
    {
        if(n%i==0) return i;
    }

    return n;
}

void buildst(num st[],num a[],num n)
{
    for(num i=0; i<n; i++)
        st[i+n] = leasPrimeDiv(a[i]);

    for (num i = n - 1; i > 0; --i)
        st[i] = max(st[i<<1],st[i<<1 | 1]);
}


num query(num st[],num l, num r ,num n)  
{  
    num res = 0; 
      
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    {
        if (l&1)  res = max(res,st[l++]); 
      
        if (r&1)  res = max(res,st[--r]); 
    } 
      
    return res; 
}

void update(num st[],num l, num r,num n)  
{
    for(num j=l; j<=r; j++)
    {
        num i=j+n; 

        if(st[i]==1) continue;

        st[i]/=leasPrimeDiv(st[i]); 
          
        for (; i > 1; i >>= 1) st[i>>1] = max(st[i],st[i^1]);
    }
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
        num n,q; cin>>n>>q; num a[n],st[2*n]; st[0]=0;

        for(num i=0; i<n; i++) cin>>a[i];

        buildst(st,a,n);

        display(st,n+n);

        while(q--)
        {
            num x,l,r;  cin>>x>>l>>r;

            if(x==1)
            {
                if(l==r)    cout<<st[l+n-1]<<" ";
                else        cout<<query(st,l-1,r,n)<<" "; // O(n)
            }
            else
            {
                update(st,l-1,r-1,n); display(st,n+n);
            }
        }

        cout<<"\n";
    }

    return 0;
}