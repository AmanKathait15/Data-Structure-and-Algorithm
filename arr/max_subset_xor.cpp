 #include<bits/stdc++.h> 
using namespace std;
#define num int

int maxSubsetXOR(int set[], int n) 
{ 
	int index = 0,res=0; 

	for (int i = 31; i >= 0; i--) 
	{ 
		int maxInd = index; 
		int maxEle = INT_MIN;

		for (int j = index; j < n; j++) 
		{ 
			if ( (set[j] & (1 << i)) != 0 and set[j] > maxEle ) maxEle = set[j], maxInd = j; 
		} 

		if (maxEle == INT_MIN) continue; 

		swap(set[index], set[maxInd]); 

		//printf("swap(%d,%d) swap(%d,%d)\n",index,maxInd,set[index],set[maxInd]);

		maxInd = index; 

		for (int j=0; j<n; j++) 
		{ 
			if (j != maxInd && (set[j] & (1 << i)) != 0) 
				set[j] = set[j] ^ set[maxInd]; 
		} 

		//for(int i=0; i<n; i++) cout<<set[i]<<" "; cout<<"\n";

		index++; 
	} 

	for (int i = 0; i < n; i++)	res ^= set[i]; 
	
	return res; 
} 

int main() 
{ 
	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n; int a[n];

		for(int i=0; i<n; i++) cin>>a[i];

		cout << maxSubsetXOR(a, n); 
	}

	return 0; 
} 
