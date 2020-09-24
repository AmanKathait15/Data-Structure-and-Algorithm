// 0 1 knapsack recursive solution
// we are given a weight matrix and cost matrix as input containing item weight and cost respectively for each valid pair of i and W max weight
// that our knapsack can handle find those wieghts which give maximum cost such that we can not break any of them

#include <bits/stdc++.h>
using namespace std;

static int i=0;

int knapsack(int weight[], int cost[], int n, int w) // n is maX weight of knapsack and n is number of items
{
	printf("\n[%d] n == %d weight ==  %d",i++,n,w);
	//base case
	if(n==0 || w==0)	return 0;
	else if(weight[n-1]>w)	return knapsack(weight,cost,n-1,w);	//if weight is greater then capacity of our knapsack 
																//then that item can not be put in our knapsack so skip that item
	else return max(cost[n-1]+knapsack(weight,cost,n-1,w-weight[n-1]) , knapsack(weight,cost,n-1,w));
}

int main()
{
	int n,w;
	cin>>n>>w;
	int weight[n],cost[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>weight[i]>>cost[i];
	}

	cout<<"maximum cost of our knapsack is "<<knapsack(weight,cost,n,w);

	return 0;
}
