#include<bits/stdc++.h>
using namespace std;

int videoStitching(vector<vector<int>> &clips, int T , int size) 
{       
    sort(clips.begin(), clips.end());
        
    vector<int> dp(101, 101);   dp[0] = 0;
        
    for(int i = 0; i < size; i++)
    {   
        int left = clips[i][0] + 1, right = clips[i][1];
        
        for(int j = left; j <= right; j++)
        {
            dp[j] = min(dp[j], dp[left - 1] + 1);
        }
    }

    return dp[T] >= 100 ? -1: dp[T];
}

int main()
{
    int n,t,x,y; cin>>n>>t; vector<vector<int>> v;

    for(int i=0; i<n; i++)
    {
        cin>>x>>y; v.push_back({x,y});
    }

    cout<<videoStitching(v,t,n)<<"\n";

    return 0;
}