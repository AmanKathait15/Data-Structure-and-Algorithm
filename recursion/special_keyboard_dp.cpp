#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/special-keyboard3018/1

int maxA(int n)
{
    if(n<7) return n;

    int dp[n];

    for(int i=1; i<7; i++) dp[i-1]=i;

    for(int i=7; i<n; i++)
    {
        dp[i-1]=0;

        for(int b=n-3; b>0; b--)
        {
            int curr = (n-b-1) * dp[b-1];

            //cout<<curr<<" "<<max<<" "<<dp[b-1]<<"\n";

            if(curr > dp[i-1]) dp[i-1] = curr;
        }
    }

    return dp[n-1];
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n; 

    cout<<maxA(n)<<"\n";

	return 0;
}
