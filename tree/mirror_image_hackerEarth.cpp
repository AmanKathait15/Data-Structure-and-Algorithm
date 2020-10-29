#include<bits/stdc++.h>
using namespace std;

//https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mirror-image-2/submissions/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,q; cin>>n>>q;

    vector<vector<int>> v(n+1,vector<int>(2,-1));

    for(int i=1; i<n; i++)
    {
        int p,c; char ch; cin>>p>>c>>ch;

        if(ch=='L') v[p][0] = c;
        else        v[p][1] = c;
    }
    
    queue<int> q1,q2; q1.push(1); q2.push(1); unordered_map<int,int> mp;

    while(!q1.empty() and !q2.empty())
    {  
        int p1 = q1.front(); q1.pop();
        int p2 = q2.front(); q2.pop();

        mp.insert({p1,p2});

        //cout<<p1<<" "<<p2<<"\n";

        if(p1!=-1)
        {
            q1.push(v[p1][0]); 
            q1.push(v[p1][1]);
        }

        if(p2!=-1)
        {
            q2.push(v[p2][1]); 
            q2.push(v[p2][0]);
        }
    }

    while(q--)
    {
        int x; cin>>x; cout<<mp[x]<<"\n";
    }
}