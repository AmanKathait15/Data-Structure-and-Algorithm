#include<bits/stdc++.h>
using namespace std;

int cst(int st[],int a[],int l,int r,int i)
{
    if(l==r)
    {
        st[i] = a[r]; return a[r];
    }

    int mid = (l+r)/2;

    st[i] = cst(st,a,l,mid,i*2) + cst(st,a,mid+1,r,i*2+1);

    return st[i];
}

int getSum(int st[],int ss,int se,int qs,int qe,int i)
{
    if (qs <= ss && qe >= se) 
        return st[i]; 
  
    if (se < qs || ss > qe) 
        return 0; 

    int mid = (ss+se)/2;

    return getSum(st, ss, mid, qs, qe, 2*i) + getSum(st, mid+1, se, qs, qe, 2*i+1);
}

void update(int st[], int ss, int se, int ui, int diff, int i) 
{ 
    if (ui < ss || ui > se) return; 
  
    st[i]+= diff; 
    
    if (se != ss) 
    { 
        int mid = (ss+se)/2;

        update(st, ss, mid, ui, diff, 2*i); 
        update(st, mid+1, se, ui, diff, 2*i+1); 
    } 
}

void display(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }   printf("\n");
}

int main()
{
    int n,h,size; cin>>n;

    h = (int)(ceil(log2(n)));   size = 2*(int)pow(2,h)-1;
    
    int a[n],st[size+1];  memset(st,0,sizeof(st));

    for(int i=0; i<n; i++) cin>>a[i];

    cst(st,a,0,n-1,1);

    display(st,size+1);

    while(1)
    {
        int c,l,r; cin>>c>>l>>r;

        if(c==0)    cout<<getSum(st,0,n-1,l,r,1)<<"\n";
        else
        {
            int diff = r-a[l];    //adding diff is easy

            a[l] = r;

            update(st,0,n-1,l,diff,1);

            display(st,size);
        }
    }

    return 0;
}