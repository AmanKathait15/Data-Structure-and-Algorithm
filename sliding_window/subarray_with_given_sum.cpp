//brute force approcah

#include<bits/stdc++.h>
using namespace std;
#define num long int

num sol(vector<num> v,num n,num k)
{
    vector<num> ans;

    for(num i=0; i<n; i++)
    {
        num sum = 0;

        for(num j=i; j<n; j++)
        {
            sum+=v[j];

            if(sum>k) break;

            if(sum==k)
            {
                printf("subarray found with index %ld - %ld\n",i,j);
                return 1;
            }
        }
    }

    return -1;
}

int main()
{
    num n,k; cin>>n>>k;

    vector<num> v(n);

    for(num i=0; i<n; i++)  cin>>v[i];

    cout<<sol(v,n,k)<<"\n";

    return 0;
}