#include<bits/stdc++.h>
using namespace std;
#define num int

int coin_change( int S[], int m, int n ) 
{  
	int table[n+1]; memset(table, 0, sizeof(table)); 

	table[0] = 1; 

	for(int i=0; i<m; i++) 
	{
		for(int j=S[i]; j<=n; j++) 
		{
			table[j] += table[j-S[i]];
		} 

		for(int k=0; k<=n; k++) cout<<S[i]<<" "; cout<<"\n";
	}

	return table[n]; 
} 

int main()
{
	short t; cin>>t;

	while(t--)
	{
		int n,v; cin>>n; int coins[n];

		for(int i=0; i<n; i++) cin>>coins[i]; cin>>v;

		cout<<coin_change(coins,n,v)<<"\n";
	}

	return 0;
}
