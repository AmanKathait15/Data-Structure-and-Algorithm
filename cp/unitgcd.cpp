#include <bits/stdc++.h>
using namespace std;
#define num unsigned long long int

int main() {
    // your code goes here
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    num t;
    cin>>t;
    while(t--)
    {
        num n; bool flag=0;
        cin>>n;
        if(n!=1)
        cout<<(n/2)<<"\n"; 

        if(n==1)
            cout<<"1\n1 1\n";
        else if(n==2)
            cout<<"2 1 2\n";
        else if(n>=3)
            cout<<"3 1 2 3\n";
        if(n>=4 && n%2==0)
        {
            n-=1; flag = 1;
        }
        for(num i=4; i<=n; i+=2)
        {
            cout<<"2 "<<i<<" "<<(i+1)<<"\n";
        }
        if(flag)
            cout<<"1 "<<(n+1)<<"\n";

    }
    return 0;
}