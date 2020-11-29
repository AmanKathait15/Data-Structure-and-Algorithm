#include <bits/stdc++.h>
using namespace std;
#define foreach(n,m,a) for(int i=0; i<n; i++) for(int j=0; j<m; j++) cout<<a[i][j]<<" "
#define vect vector<vector<int>>
#define P pair<int,int>

//https://practice.geeksforgeeks.org/problems/number-of-paths0926/

int nop(int n,int m)
{
    if(n==1 or m==1) return 1;

    return nop(n-1,m) + nop(n,m-1);
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n,m; cin>>n>>m;

    cout<<nop(n,m)<<"\n";

	return 0;
}
