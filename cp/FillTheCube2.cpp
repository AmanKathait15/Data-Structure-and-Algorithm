#include<bits/stdc++.h>
#define num int
using namespace std;
#define R 100 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	num n,l; cin>>n; num row[n]={0},col[n]={0}; l=n*n;

	bool a[R][R],b[R][R];

	for(num i=0; i<l; i++)
	{
		char ch;	cin>>ch;

		if(ch=='D')
		{
			col[i%n]++;
			row[i/n]++;
		}
	}

	for(num i=0; i<n; i++)
		cout<<row[i]<<" "<<col[i]<<"\n";

	num rmax =0 ;

	for(num i=0; i<n; i++)
	{
		if(row[i]>rmax)
		for(num j=i+1; j<n && j<i+row[i]-1; j++)
		{
			if(row[j]<row[i])
				break;
			else
			{
				num tmp = j-i+1;

				if(tmp > rmax)
					rmax = tmp;
			}
		}
	}

	cout<<rmax;

	
	return 0;
}