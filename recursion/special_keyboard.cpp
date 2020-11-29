#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/special-keyboard3018/1

int maxA(int n)
{
    if(n<7) return n;

    int max = 0,b;

    for(int b=n-3; b>0; b--)
    {
        int curr = (n-b-1) * maxA(b);

        cout<<curr<<" "<<max<<" "<<maxA(b)<<"\n";

        if(curr > max) max = curr;
    }

    return max;
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n; 

    cout<<maxA(n)<<"\n";

	return 0;
}
