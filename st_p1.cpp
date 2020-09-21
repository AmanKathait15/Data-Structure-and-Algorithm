#include<bits/stdc++.h>

using namespace std;

void buildst(num st[],num a[],num n)
{
	for (num i = n - 1; i > 0; --i)
		st[i] = st[i<<1] + st[i<<1 | 1];
}

num query(num st[],num l, num r ,num n)  
{  
    num res = 0;

    if(l==r) res = st[l+n]; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    {
    	printf("(%d:%d) (%d %d)\n",l,r-1,(l&1),(r&1));

        if (l&1) 			// if last bit is 0 i.e l is even then true  
            res += st[l++]; 
      
        if (r&1)  
            res += st[--r]; 

        //printf("(%d:%d) (%d %d)\n",l,r,(l&1),(r&1));
    } 
      
    return res; 
}

void update(num st[],num i, num val,num n)  
{
	i+=n; st[i]=val; 
      
    // move upward and update parents 
    for (; i > 1; i >>= 1) st[i>>1] = st[i] + st[i^1]; //same as st[i] = st[i]+st[i+1];
} 
 
void display(num a[],num n)
{
    for(num i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }   printf("\n");
}

num main()
{
	num n,q; cin>>n>>q; num a[n],st[2*n];	st[0]=0;	// use 1 based indexing in seg tree

	for(num i=0; i<n; i++)
	{
		cin>>a[i]; st[n+i] = a[i];
	}

	buildst(st,a,n); // O(n)

	while(q--)
	{
		display(st,2*n);

		num c,l,r; cin>>c>>l>>r;

		if(c)	cout<<query(st,l,r,n)<<"\n";
		else 	update(st,l,r,n);
	}

	return 0;
}