#include<bits/stdc++.h>
using namespace std;
#define num int

int lswrc(string str,int n, int k)
{
	int i=0,j=0,m=0,u=0,b[26]; memset(b,0,sizeof(b)); 

	for(int i=0; i<n; i++) if(b[str[i]-97]==0) { u++; b[str[i]-97]++; } if(u<k) return -1; u=0;

	memset(b,0,sizeof(b)); 

	while(i<n)
	{
		//for(int i=0; i<n; i++) cout<<b[i]<<" "; cout<<" : "<<u<<"\n";

		if(j>n || u>k)
		{
			if((j-i-1)>m) m = j-i-1;

			b[str[i]-97]--; if(b[str[i]-97]==0) u--;
			
			i++;
		}
		else if(b[str[j]-97]==0)
		{
			u++; b[str[j++]-97]++;
		}
		else b[str[j++]-97]++;
	}

	return m;
}

int main()
{
	int t,k; cin>>t;

	while(t--)
	{
		string str; cin>>str; cin>>k; cout<<lswrc(str,str.length(),k)<<"\n";
	}

	return 0;
}