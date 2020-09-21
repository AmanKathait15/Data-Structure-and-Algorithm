#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n)
{
	stack<int> st;

	for(int i=0; i<n; i++)
	{
		if(st.empty())
		{
			st.push(a[i]); continue;
		}
		
		while(!st.empty() && a[i]>st.top())
		{
			cout<<st.top()<<"-->"<<a[i]<<"\n"; st.pop();
		}	st.push(a[i]);
	}

	while(!st.empty())
	{
		cout<<st.top()<<"--> -1\n"; st.pop();
	}
}

int main()
{
	int n; cin>>n; int a[n];

	for(int i=0; i<n; i++) cin>>a[i]; solve(a,n);

	return 0;
}