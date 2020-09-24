#include<bits/stdc++.h>
#define num long int
using namespace std;

num getMid(num s, num e) { return s + (e -s)/2; } 

num constructSTUtil(num arr[], num ss, num se, num *st, num si)  
{  

    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
    num mid = getMid(ss, se);  
    st[si] = min(constructSTUtil(arr, ss, mid, st, si*2+1) , constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  

num rangeOP(num *st, num ss, num se, num qs, num qe, num si)  
{  
    if (qs <= ss && qe >= se)  
        return st[si];  
  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return 0;  
  
    // If a part of this segment overlaps with the given range  
    num mid = getMid(ss, se);  
    return min(rangeOP(st, ss, mid, qs, qe, 2*si+1) , rangeOP(st, mid+1, se, qs, qe, 2*si+2));  
} 

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    
    num n,q;
    cin>>n;
    num a[n];
    for(num i=0; i<n; i++)
    cin>>a[i];

    num x = (num)(ceil(log2(n)));  
  
    num max_size = 2*(num)pow(2, x) - 1;  

    num *st = new num[max_size];  
  
    constructSTUtil(a, 0, n-1, st, 0);  

    for(num i=0; i<max_size; i++)
        cout<<st[i]<<" ";

    cin>>q;

    while(q--)
    {
        num l,r;
        cin>>l>>r;

        cout<<rangeOP(st,0,n-1,l,r,0)<<"\n";
    }

    return 0;
}