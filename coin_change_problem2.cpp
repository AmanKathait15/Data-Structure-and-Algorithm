#include<bits/stdc++.h> 
using namespace std; 

int coin_change( int S[], int m, int n ) 
{ 
	int i, j, x, y; 

	int table[n + 1][m]; memset(table,0,sizeof(table));
	 
	for (i = 0; i < m; i++) 
		table[0][i] = 1; 

	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 

			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : 0; 

			// total count 
			table[i][j] = x + y; 
		} 

		/*for(int k=0; k<=n; k++)
		{
			for(int j=0; j<=n; j++) cout<<table[k][j]<<" "; cout<<"\n";
		}*/
	} 
	return table[n][m - 1]; 
} 

// Driver Code 
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
