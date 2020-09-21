#include<bits/stdc++.h>
using namespace std;
#define num int

num query(num bit[],num i,num res)
{
	for(; i>0; i = i & (i-1))  	res+= bit[i];	 	return res;
}

void update(num bit[],num i,num val,num n)  
{
	for(; i<=n; i+= i & (-i))	bit[i] += val;
} 

void display(num a[],num n)
{
    for(num i=0; i<=n; i++)
    {
        printf("%d ",a[i]);
    }   printf("\n");
}

int main()
{
	num n,q; cin>>n>>q; num a[n],bit[n+1]; memset(bit,0,sizeof(bit));

	for(num i=0; i<n; i++)
	{
		cin>>a[i]; update(bit,i+1,a[i],n); //built bit simultaneously
	}

	while(q--)
	{
		display(bit,n);	num c,i,val; cin>>c>>i;

		if(c)	cout<<query(bit,i,0)<<"\n";
		else
		{	
			cin>>val; update(bit,i,(val-a[i-1]),n); a[i-1]=val; display(a,n-1);
		}
	}

	return 0;
}