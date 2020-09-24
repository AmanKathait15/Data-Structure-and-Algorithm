#include<bits/stdc++.h>
using namespace std;
#define num int

int main()
{
	cout<<"enter a string : "; string str,output=""; cin>>str; char f[26]={0};

	bool flag = 0; num n=str.length();

	for(num i=0; i<n; i++)
	{
		f[str[i]-'a']++;
	}

	priority_queue<pair<num,char>> heap;

	for(num i=0; i<26; i++)
	{
		if(n<(2*f[i]-1))
		{
			flag = 1; break;
		}
		if(f[i])	heap.push(make_pair(f[i],'a'+i));
	}

	if(flag)
	{
		cout<<"-1\n"; return 0;
	}

	pair<num,num> prev = {-1,'#'};

	while(!heap.empty())
	{
		pair<num,num> p = heap.top(); heap.pop();

		output+= p.second; p.first--;

		if(prev.first > 0)	heap.push(prev);

		prev = p;
	}

	cout<<output<<"\n";

	return 0;
}