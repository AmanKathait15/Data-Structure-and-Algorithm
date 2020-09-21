#include<bits/stdc++.h> 
using namespace std; 

int minSwaps(int arr[], int n) 
{ 
	pair<int, int> arrPos[n]; 

	for (int i = 0; i < n; i++) 
	{ 
		arrPos[i].first = arr[i]; 
		arrPos[i].second = i; 
	}

	sort(arrPos, arrPos + n); cout<<"after sorting\n";

	for(int i=0; i<n; i++)
	{
		cout<<arrPos[i].first<<" "<<arrPos[i].second<<"\n";
	}

	vector<bool> vis(n, false); 

	int ans = 0; 

	for (int i = 0; i < n; i++) 
	{ 
		if (vis[i] || arrPos[i].second == i) 	continue; 

		int cycle_size = 0 , j = i; cout<<j<<" ";

		while (!vis[j]) 
		{ 
			vis[j] = 1; 

			j = arrPos[j].second; 	cycle_size++; cout<<j<<" "; 
		}

		cout<<cycle_size<<"\n"; 

		if (cycle_size > 0) 
		{ 
			ans += (cycle_size - 1); 
		} 
	} 

	return ans; 
} 

int main() 
{ 
	int n; cin>>n; int a[n];

	for(int i=0; i<n; i++) cin>>a[i];

	cout<<minSwaps(a,n)<<"\n";

	return 0; 
} 
