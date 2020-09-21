#include<bits/stdc++.h>
using namespace std;

int videoStitching(vector<vector<int>> &clips, int T) 
{
    int m = clips.size();
        
    sort(clips.begin(), clips.end());

    /*for(int i=0; i<clips.size(); i++)
    {
        cout<<clips[i][0]<<" "<<clips[i][1]<<"\n";
    }*/
        
    vector<int> dp(101, 101);
        
    dp[0] = 0; // initialization

    for(int i=0; i<T; i++)
    {
        cout<<dp[i]<<" ";
    }   cout<<"\n";
        
    for(int i = 0; i < m; i++)
    {   
        int left = clips[i][0] + 1, right = clips[i][1];

        //printf("left %d right %d \n",left,right);
        
        for(int j = left; j <= right; j++)
        {
            //printf("min(%d , %d)\n",dp[j],dp[left-1]+1);
            dp[j] = min(dp[j], dp[left - 1] + 1);
        }

        for(int i=0; i<T; i++)
        {
            cout<<dp[i]<<" ";
        }   cout<<"\n";
        
    }

    return dp[T] >= 100 ? -1: dp[T];
}

int main()
{
    int n,t; cin>>n>>t;

    vector<vector<int>> v;

    for(int i=0; i<n; i++)
    {
        int x,y; cin>>x>>y;

        vector<int> tmp({x,y});

        v.push_back(tmp);
    }

    cout<<videoStitching(v,t)<<"\n";

    return 0;
}