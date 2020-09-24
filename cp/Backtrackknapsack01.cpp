// 0 1 knapsack dynamic programing solution
// we are given a weight matrix and cost matrix as input containing item weight and cost respectively for each valid pair of i and W max weight
// that our knapsack can handle find those wieghts which give maximum cost such that we can not break any of them
//also print the set which we include in our knapsack in form {0,1,0,1,0} suppose 2 nad 4 th include and other are not 

#include <bits/stdc++.h>
using namespace std;
#define size 100
static int ks[size][size];

void backtrack(bool item[],int cost[],int n,int w)
{
	int res = ks[n][w],i=n;
	while(res)
	{
		while(res && binary_search(ks[i],ks[i]+(w+1),res))	i--;
		res-=cost[i]; item[i]=1;
	}
	cout<<"\nby including these items we get the maximum cost of our knapsack : \n";
	for (int i = 0; i < n; ++i)
	cout<<item[i]<<" ";
}

int knapsack(int weight[], int cost[], int n, int w) // w is capacity of knapsack and n is number of items
{
	for (int i = 0; i<=n; ++i)
	{
		for (int j = 0; j<= w; ++j)
		{
			if(i==0 || j==0)	ks[i][j] = 0;					//base case
			else if(weight[i-1]>j)	ks[i][j] = ks[i-1][j];		// if weight is greater then capacity
			else
			{
				ks[i][j] = max(ks[i-1][j] , cost[i-1] + ks[i-1][j-weight[i-1]]);			// if weight is not greater then capacity 
			}

			cout<<ks[i][j]<<" ";
		}	cout<<"\n";
	}
	return ks[n][w];
}

int main()
{
	int n,w;
	cin>>n>>w;
	int weight[n],cost[n];	bool item[n]={0};

	for (int i = 0; i < n; ++i)
	{
		cin>>weight[i]>>cost[i];
	}
	int ans = knapsack(weight,cost,n,w);
	//cout<<"maximum cost of our knapsack is "<<ans;

	backtrack(item,cost,n,w);

	return 0;
}