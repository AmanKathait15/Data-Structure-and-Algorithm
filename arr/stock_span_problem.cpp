#include<bits/stdc++.h>
using namespace std;
#define num long int

void stock_span(num s[],num a[], num n)
{
	stack<int> st; st.push(0); s[0]=1;

	for(int i=1; i<n; i++)
	{
		while(!st.empty() && a[i]>=a[st.top()])
		{
			st.pop(); 
		}

		s[i] = st.empty()? i+1 : i-st.top();

		st.push(i);
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