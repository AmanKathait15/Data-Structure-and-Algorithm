#include<bits/stdc++.h>
using namespace std;
#define num long int

void stock_span(num s[],num a[], num n)
{
	stack<int> st; st.push(0); s[0]=1;

	for(int i=1; i<n; i++)
	{
		int c=1;	while((i-c)>=0 && a[i]>=a[i-c])	c+= s[i-c];	

		s[i] = c;
	}
}

int main()
{
	num n; cin>>n; num a[n],s[n];

	for(num i=0; i<n; i++) cin>>a[i];

	stock_span(s,a,n);

	for(num i=0; i<n; i++) cout<<s[i]<<" "; cout<<"\n";

	return 0;
}