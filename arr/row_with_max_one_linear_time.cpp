#include<bits/stdc++.h>
using namespace std;
#define fast(i,v,n) for(int i=v; i<n; i++)
#define display(i,j,n,m,a) fast(i,0,n) { fast(j,0,m) cout<<a[i][j]<<" "; cout<<"\n"; }
#define Vect vector<vector<bool>>

int row_with_max_1(Vect &a,int n, int m)
{
	int max_row = -1, j = m-1;

	for(int i=0; i<n; i++)
	{
		while(j>=0 and a[i][j]==1)
		{
			j--; max_row = i;
		}
	}

	return max_row;
}

int main()
{
	int n,m; cin>>n>>m; Vect a(n);

	fast(i,0,n) fast(j,0,m) { bool x; cin>>x; a[i].push_back(x); }

	display(i,j,n,m,a);

	cout<<row_with_max_1(a,n,m)<<"\n";

	return 0;
}