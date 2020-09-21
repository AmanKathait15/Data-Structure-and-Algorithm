#include<bits/stdc++.h>
using namespace std;

int min_platform(multimap<int,char> &mp,int n)
{
    int m=0,c=0;

    for(auto i=mp.begin(); i!=mp.end(); i++)
    {
        if(i->second == 'a')    c++;
        else                    c--;

        if(c>m) m=c;
    }

    return m;
}

int main()
{
    int n,x,y; cin>>n; multimap<int,char> mp;

    for(int i=0; i<n; i++)
    {
        cin>>x>>y;  mp.insert({x,'a'}); mp.insert({y,'d'});
    }

    cout<<min_platform(mp,n)<<"\n";

    return 0;
}