#include<bits/stdc++.h>
using namespace std;
#define max 100

static int a[max][max];

vector<pair<int,int>> sol({{1,1},{2,2},{3,1},{1,3},{2,2},{3,3},{5,1},{1,5},{3,3},{4,4},{7,1},{1,7},{4,4},{5,5},{8,2},{2,8},{5,5},{6,6},{8,4},{4,8},{6,6},{7,7},{8,6},{6,8},{7,7},{8,8}});

void setboard(int x1,int y1,int x2,int y2)
{
	while(x1!=x2 && y1!=y2)
		a[x1--][y1++]=1;
}

void display(int n)
{
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}
}

int main()
{
	int r,c,count=0; bool flag = false;
	cin>>r>>c;

	display(8);

	for(int i=0; i<26; i++)
	{
		if((sol[i].first+sol[i].second)==(r+c))
			flag=true;
		if(flag)
		{
			count++;
			a[sol[i].first][sol[i].second]=1;
			cout<<sol[i].first<<" "<<sol[i].second<<"\n";
		}
	}
	display(8);
	for (int i = 0; i <26-count; ++i)
	{
		a[sol[i].first][sol[i].second]=1;
		cout<<sol[i].first<<" "<<sol[i].second<<"\n";
	}
	display(8);
	return 0;
}