#include<bits/stdc++.h>
using namespace std;
#define num long int

void update(num st[],num l,num val,num n)
{
    l+=n; st[l]=val;

    for(; l>1; l>>=1)   st[l>>1] = st[l] + st[l^1];
}

num query(num st[],num l,num r,num n)
{
    num res = 0;

    for(l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if(l&1) res += st[l++];
        if(r&1) res += st[--r];
    }

    return res;
}

void display(num a[],num n)
{
    for(num i=0; i<n; i++)    cout<<a[i]<<" ";    printf("\n");
}

int main()
{
    num n,q; cin>>n>>q; num a[n],st[n+n];

    memset(a,0,sizeof(a)); memset(st,0,sizeof(st));

    while(q--)
    {
        //display(a,n); display(st,n+n);

        num ch,l,r; cin>>ch;

        if(ch==1)
        {
            cin>>l; l--; a[l]++; update(st,l,a[l],n);
        }
        else if(ch==2)
        {
            cin>>l; l--;

            if(a[l])
            {
                a[l]--; update(st,l,a[l],n);
            }
        }
        else
        {
            cin>>l>>r;

            if(l==r) cout<<st[l+n-1]<<"\n"; 
            else     cout<<query(st,l-1,r,n)<<"\n";
        }
    }
}