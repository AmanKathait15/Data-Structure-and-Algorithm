#include <bits/stdc++.h>
using namespace std;
#define num long int


int main() {
	// your code goes here
	
	num n;
	cin>>n;

	map<num,num> mp;

	for(num i=0; i<=n; i++)
	{
		for(num j=i+1; j<=n; j++)
		{
			mp[abs(pow(i,2)-pow(j,2))]++;
		}
	}

	for(auto i=mp.begin(); i!=mp.end(); i++)
	{
		cout<<i->first<<" "<<i->second<<"\n";
	}
	return 0;
}