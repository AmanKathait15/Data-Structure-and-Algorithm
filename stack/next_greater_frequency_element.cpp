#include<bits/stdc++.h>
using namespace std;
#define num long int

void solve(num a[],num f[],num n)
{
   stack<int> st; num res[n+1]; st.push(0);
   
   for(num i=1; i<n; i++)
   {
       if(f[st.top()]>f[a[i]])
       {
           st.push(a[i]); continue;
       }
       
       while(!st.empty() and f[a[i]]>f[st.top()])
       {
           res[st.top()] = a[i];  st.pop();
       }   st.push(i);
   }
   
   while(!st.empty())
   {
       res[st.top()] = -1; st.pop();
   }
   
   for(num i=0; i<n; i++) cout<<res[i]<<" ";
}

int main()
{
	int t; cin>>t;
	
	while(t--)
	{
	    num n,max=0; cin>>n; num a[n];

	    for(num i=0; i<n; i++)
	    {
	    	cin>>a[i]; if(a[i]>max) max=a[i];
	    }

	    num f[max+1]={0};

	    for(num i=0; i<n; i++) f[a[i]]++;
	    
	    solve(a,f,n); cout<<"\n";
	}

	return 0;
}