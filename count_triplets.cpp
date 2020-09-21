#include<bits/stdc++.h>
using namespace std;

int count_triplets(map<int,int> &mp,vector<int> v,int n)
{
    int c=0;

    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            int key = v[i]+v[j];

            if(mp[key]) c+=mp[key];
        }
    }

    return c;
}

int main()
{
    int n,i=0; cin>>n; vector<int> v(n); map<int,int> mp;

    for(int i=0; i<n; i++)
    {
        cin>>v[i]; mp[v[i]]++;
    }

    cout<<count_triplets(mp,v,n)<<"\n";

    return 0;
}