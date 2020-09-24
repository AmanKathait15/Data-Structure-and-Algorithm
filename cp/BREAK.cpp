#include<bits/stdc++.h>
using namespace std;
#define num unsigned long long int

int main()
{
	num t,s;
	cin>>t>>s;

	while(t--)
	{
		num n; bool flag = true;
		cin>>n;

		vector<num> a(n),b(n);

		for(num i=0; i<n; i++)
			cin>>a[i];
		for(num i=0; i<n; i++)
			cin>>b[i];

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		set<num> table;

		for(num i=0; i<n; i++)
		{
			if(a[i]>=b[i])
			{
				flag=false; break;
			}
			else
			{
				if(table.empty())
				{
					table.insert(a[i]); table.insert(b[i]);
				}
				else if(table.find(a[i])==table.end())
				{
					flag = false; break;
				}
				else
				{
					table.insert(a[i]); table.insert(b[i]);	
				}
			}
		}

		if(flag)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}
	return 0;
}