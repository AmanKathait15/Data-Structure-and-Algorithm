#include<bits/stdc++.h>
#define num int
using namespace std;
#define R 100 

num solve(bool M[R][R],num n) 
{ 
	int i,j; 
	int S[R][R]; 
	int max_of_s, max_i, max_j; 

	for(i = 0; i < n; i++) 
		S[i][0] = M[i][0]; 
	
	for(j = 0; j < n; j++) 
		S[0][j] = M[0][j]; 
		
	for(i = 1; i < n; i++) 
	{ 
		for(j = 1; j < n; j++) 
		{ 
			if(M[i][j] == 1) 
				S[i][j] = min(S[i][j-1],min( S[i-1][j], 
								S[i-1][j-1])) + 1; 
			else
				S[i][j] = 0; 
		} 
	} 
	
	max_of_s = S[0][0]; max_i = 0; max_j = 0; 
	for(i = 0; i < n; i++) 
	{ 
		for(j = 0; j < n; j++) 
		{ 
			if(max_of_s < S[i][j]) 
			{ 
				max_of_s = S[i][j]; 
				max_i = i; 
				max_j = j; 
			} 
		}			 
	} 

	/*
	for(i = max_i; i > max_i - max_of_s; i--) 
	{ 
		for(j = max_j; j > max_j - max_of_s; j--) 
		{ 
			cout << M[i][j] << " "; 
		} 
		cout << "\n"; 
	}*/

	return min(max_i,max_j)+1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	num n,l,c=0; cin>>n; num row[n]={0},col[n]={0}; l=n*n;

	bool a[R][R],b[R][R];

	for(num i=0; i<l; i++)
	{
		char ch;	cin>>ch;

		if(ch=='D')
		{
			col[i%n]++;
			row[i/n]++;
			c++;
		}
	}

	if(c==l)
	{
		cout<<n; return 0;
	}
	if(c==0)
	{
		cout<<"0"; return 0;
	}

	for(num i=0; i<n; i++)
	{
		//cout<<row[i]<<" "<<col[i]<<"\n";

		for(num j=0; j<row[i]; j++)
			a[i][j]=1;
		for(num j=0; j<col[i]; j++)
			b[i][j]=1;
	}

	
	/*for(num i=0; i<n; i++)
	{
		for(num j=0; j<n; j++)
		{
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}

	for(num i=0; i<n; i++)
	{
		for(num j=0; j<n; j++)
		{
			cout<<b[i][j]<<" ";
		}	cout<<"\n";
	}*/

	//cout<<solve(a,n)<<" "<<solve(b,n);
	cout<<max(solve(a,n),solve(b,n));
	return 0;
}