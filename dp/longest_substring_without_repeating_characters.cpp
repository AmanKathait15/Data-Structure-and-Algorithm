#include<bits/stdc++.h>
using namespace std;
#define num long int

int lswrc(string str,int n)
{
	int i=0,j=0,m=1; bitset<150> b; 

	while(j<n)
	{
		while(j<n && b[str[j]]==0) b[str[j++]]=1;

		//cout<<b<<" "; printf("%d : %d = %d\n",j,i,j-i);

		if((j-i)>m) m = j-i;

		b[str[i++]]=0;
	}

	if((j-i)>m) m = j-i;

	return m;
}

int main()
{
	int t; cin>>t;

	while(t--)
	{
		string str; cin>>str; cout<<lswrc(str,str.length())<<"\n";
	}

	return 0;
}