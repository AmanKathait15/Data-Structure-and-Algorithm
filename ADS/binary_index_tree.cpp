#include<bits/stdc++.h>
using namespace std;

int query(int bit[],int i,int res)
{
	while(i>0)
	{
		res+= bit[i]; i-= (i & (-i));
	}

	return res;
}

void update(int bit[],int i,int val,int n)  
{
	while(i<=n)
	{
		bit[i] += val; i+= i & (-i);
	}
} 

void display(int a[],int n)
{
    for(int i=0; i<=n; i++)
    {
        printf("%d ",a[i]);
    }   printf("\n");
}

int main()
{
	int n,q; cin>>n>>q; int a[n],bit[n+1]; memset(bit,0,sizeof(bit));

	for(int i=0; i<n; i++)
	{
		cin>>a[i]; update(bit,i+1,a[i],n); //built bit simultaneously
	}

	while(q--)
	{
		display(bit,n);

		int c,i,val; cin>>c>>i;

		if(c)	cout<<query(bit,i,0)<<"\n";
		else
		{	
			cin>>val; update(bit,i,(val-a[i-1]),n); a[i-1]=val; display(a,n-1);
		}
	}

	return 0;
}