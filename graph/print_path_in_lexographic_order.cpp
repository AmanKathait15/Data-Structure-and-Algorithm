#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reconstruct-itinerary/

int main()
{
	int n; cin>>n; unordered_map<string,multiset<string>> graph;

	for(int i=0; i<n; i++)
	{
		string from,to; cin>>from>>to; graph[from].insert(to);
	}

	stack<string> st; st.push("start"); vector<string> ans;

	while(!st.empty())
	{
		string str = st.top();

		if(graph[str].size()==0)
		{
			ans.push_back(str); st.pop();
		}
		else
		{
			auto it = graph[str].begin();

			st.push(*it); graph[str].erase(it);
		}
	}

	for(auto i=ans.rbegin(); i!=ans.rend(); i++) cout<<*i<<" "; cout<<"\n";

	return 0;
}