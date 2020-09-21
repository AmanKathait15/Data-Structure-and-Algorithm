#include <bits/stdc++.h> 
using namespace std;
#define num long int 

num findMissing(vector<num> &v,num n)
{
	for(num i=0; i<n; i++)
	{
		if(abs(v[i])+1 < n && v[abs(v[i])-1]>0)	v[abs(v[i])-1] = -v[abs(v[i])-1];

		for(num j=0; j<n; j++) cout<<v[j]<<" "; cout<<"\n";
	}

	for(num i=0; i<n; i++)
	{
		if(v[i]>0) return i+1;
	}

	return 0;
} 

int main() 
{ 
	num t; cin>>t;

	while(t--)
	{
		num n,x; cin>>n; vector<num> v;

		for(num i=0; i<n; i++)
		{
			cin>>x; if(x>0) v.push_back(x);
		}

		cout<<findMissing(v,v.size())<<"\n";
	}

	return 0; 
}