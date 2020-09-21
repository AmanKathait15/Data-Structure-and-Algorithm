#include<bits/stdc++.h> 
using namespace std;
#define num int
#define fraction double

typedef struct node
{
	fraction weight,value;
} knapsack;

bool compare(knapsack a,knapsack b)
{
	fraction x = a.value/a.weight;
	fraction y = b.value/b.weight;

	return (x>y)?1:0;
}

fraction fractional_knapsack(knapsack k[], num n , num capacity)
{
	sort(k,k+n,compare); fraction max_val = 0, curr_weight=0;

	for(int i=0; i<n; i++)
	{
		if((curr_weight + k[i].weight)<capacity)
		{
			max_val+= k[i].value; curr_weight+=k[i].weight;
		}
		else
		{
			max_val+= k[i].value * (capacity - curr_weight)/k[i].weight; break;
		}
	}

	return max_val;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		num n,W; cin>>n>>W; knapsack k[n];

		for(num i=0; i<n; i++)
		{
			cin>>k[i].value>>k[i].weight;
		}

		printf("%0.2lf\n",fractional_knapsack(k,n,W));
	}

	return 0; 
} 