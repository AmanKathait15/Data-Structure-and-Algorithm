#include<bits/stdc++.h>
using namespace std;
#define num int

int lswrc(string str,int n)
{
	int i=0,j=0,m=1; bitset<150> b; 

	short c = 0;

	while(j<n)
	{
		while(j<n && ((c & 1 << (str[j]-97)) == 0) )  c  = c | 1 << (str[j++] - 97); 

		//cout<<b<<" "; printf("%d : %d = %d\n",j,i,j-i);

		cout<<c<<" ";

		if((j-i)>m) m = j-i;

		c  = c & (~ ( 1 << (str[j++] - 97)));

		cout<<c<<"\n";
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