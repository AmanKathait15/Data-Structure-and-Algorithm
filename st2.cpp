#include<bits/stdc++.h>
using namespace std;
#define num long int

num cst(num st[],num a[],num l,num r,num i)
{
    if(l==r)
    {
        st[i] = a[r]%5==0 ? 1 : 0; return st[i];
    }

    num mid = (l+r)/2;

    st[i] = cst(st,a,l,mid,i*2) + cst(st,a,mid+1,r,i*2+1);

    return st[i];
}

num getSum(num st[],num ss,num se,num qs,num qe,num i)
{
    if (qs <= ss && qe >= se) 
        return st[i]; 
  
    if (se < qs || ss > qe) 
        return 0; 

    num mid = (ss+se)/2;

    return getSum(st, ss, mid, qs, qe, 2*i) + getSum(st, mid+1, se, qs, qe, 2*i+1);
}

/*void update(num st[], num ss, num se, num ui, num diff, num i) 
{ 
    if (ui < ss || ui > se) return; 
  
    st[i]+= diff; 
    
    if (se != ss) 
    { 
        num mid = (ss+se)/2;

        update(st, ss, mid, ui, diff, 2*i); 
        update(st, mid+1, se, ui, diff, 2*i+1); 
    } 
}*/

void display(num a[],num n)
{
    for(num i=0; i<n; i++)
    {
        printf("%ld ",a[i]);
    }   printf("\n");
}

int main()
{
    num t; cin>>t;

    while(t--)
    {
        num n,h,size,q; cin>>n>>q;

        h = (num)(ceil(log2(n)));   size = 2*(num)pow(2,h)-1;
        
        num a[n],st[size+1];  memset(st,0,sizeof(st));

        for(num i=0; i<n; i++) cin>>a[i];

        cst(st,a,0,n-1,1);  // O(n)

        //display(st,size+1);

        while(q--)
        {
            num l,r; cin>>l>>r;

            cout<<getSum(st,0,n-1,l,r,1)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}