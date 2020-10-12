#include <bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/find-the-running-median

int main()
{
    int n; cin>>n; vector<float> v;

    while(n--)
    {
        float x; cin>>x; v.push_back(x);

        int size = v.size();

        sort(v.begin(),v.end());

        if(size%2!=0) printf("%0.1f\n",v[size/2]);
        else
        {
            printf("%0.1f\n",(v[size/2]+v[size/2-1])/2);
        }
    }
    
    return 0;
}
