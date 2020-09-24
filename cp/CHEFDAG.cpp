#include <bits/stdc++.h>
using namespace std;

struct graph
{
    int dest;
    graph *next;
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int parent[n];
	    graph *node[n]={NULL};
	    
	    set<pair<int,int>> set;
	    
	    while(k--)
	    {
	        int s,d;
	        cin>>s>>d;
	        
	        if(set.empty())
	        set.insert(make_pair(s,d));
	        else if(set.find(make_pair(d,s))!=set.end())
	        set.erase(make_pair(d,s));
	        else set.insert(make_pair(s,d));
	    }
	    
	    for(auto i=set.begin(); i!=set.end(); i++)
	    cout<<i->first<<" "<<i->second;
	}
	return 0;
}