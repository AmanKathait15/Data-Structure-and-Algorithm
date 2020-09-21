#include<bits/stdc++.h>
using namespace std;

int min_platform(vector<vector<int>> &time , int n)
{
    int m=0;

    for(int i=0; i<n-1; i++)
    {
        int c=0;

        for(int j=i+1; j<n; j++)
        {
            if((time[i][0]>=time[j][0] && time[i][0]<=time[j][1]) || (time[j][0]>=time[i][0] && time[j][0]<=time[i][1]))    c++;
        }

        if(c>m) m=c;
    }

    return m+1;
}

int main()
{
    int n,t,x,y; cin>>n; vector<vector<int>> v;

    for(int i=0; i<n; i++)
    {
        cin>>x>>y; v.push_back({x,y});
    }

    cout<<min_platform(v,n)<<"\n";

    return 0;
}