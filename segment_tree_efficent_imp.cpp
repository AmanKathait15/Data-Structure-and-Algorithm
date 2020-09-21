#include<bits/stdc++.h>
using namespace std;

void buildst(int st[],int a[],int n)
{
	//for(int i=0; i<n; i++)	st[n+i]=a[i]; 	// insert leaf node from n

	for (int i = n - 1; i > 0; --i)
	{
		//printf("st[%d] = st[%d] + st[%d]\n",i,i<<1,(i<<1 | 1));

		st[i] = st[i<<1] + st[i<<1 | 1]; 	// left shift operatpor 
	}
}

int query(int st[],int l, int r ,int n)  
{  
    int res = 0;

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

void update(int st[],int i, int val,int n)  
{
	i+=n; st[i]=val; 
      
    // move upward and update parents 
    for (; i > 1; i >>= 1) st[i>>1] = st[i] + st[i^1]; //same as st[i] = st[i]+st[i+1];
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
	int n,q; cin>>n>>q; int a[n],st[2*n];	st[0]=0;	// use 1 based indexing in seg tree

	for(int i=0; i<n; i++)
	{
		cin>>a[i]; st[n+i] = a[i];
	}

	buildst(st,a,n); // O(n)

	while(q--)
	{
		display(st,2*n);

		int c,l,r; cin>>c>>l>>r;

		if(c)	cout<<query(st,l,r,n)<<"\n";
		else 	update(st,l,r,n);
	}

	return 0;
}