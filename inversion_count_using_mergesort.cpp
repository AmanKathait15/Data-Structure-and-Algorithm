#include<iostream> 
using namespace std;
#define num int

void display(num a[],num l,num r)
{
    for(num i=l; i<=r; i++) cout<<a[i]<<" "; cout<<"\n";
}

num merge(num a[],num b[],num l,num mid,num r)
{
    num invcount=0,i=l,k=l,j=mid;

    while(i<mid && j<=r)
    {
        if(a[i]>a[j])
        {
            invcount += mid-i; b[k++]=a[j++];
        }
        else b[k++] = a[i++];
    }

    while(i<mid) b[k++]=a[i++];
    while(j<=r)  b[k++]=a[j++];

    for(num i=l; i<=r; i++) a[i]=b[i];

    display(a,l,r); cout<<invcount<<"\n";

    return invcount;
}

num mergesort(num a[],num b[],num l,num r)
{
    num invcount = 0;

    if(l<r)
    {
        num mid = l+(r-l)/2;

        invcount+= mergesort(a,b,l,mid);
        invcount+= mergesort(a,b,mid+1,r);

        invcount+= merge(a,b,l,mid+1,r);
    }

    return invcount;
}

int main() 
{
    num t; cin>>t;

    while(t--)
    {
        num n; cin>>n; num a[n],b[n];

        for(num i=0; i<n; i++) cin>>a[i];

        cout<<mergesort(a,b,0,n-1)<<"\n";
    }
    return 0; 
} 