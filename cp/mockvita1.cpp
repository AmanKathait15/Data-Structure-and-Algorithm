#include<bits/stdc++.h>
using namespace std;
#define num long int

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	num n,diff=0; cin>>n;

	string str; cin>>str; map<char,num> mp; 

	for(num i=0; i<n; i++)
	{
		char ch; cin>>ch; mp[ch]++;
	}

	for(num i=0; i<n; i++)
	{
		if(str[i]=='r' && mp['r'])	mp['r']--;
		else if(str[i]=='m' && mp['m']) mp['m']--;
		else
		{
			diff = n-i; break;
		}
	}

	cout<<diff;

	return 0;
}