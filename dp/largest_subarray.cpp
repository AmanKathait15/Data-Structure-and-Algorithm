#include<bits/stdc++.h>
using namespace std;
#define num long int

num maxSubArraySum(num a[], num size) 
{ 
    num max_so_far = INT_MIN, max_ending_here = 0; 

    for (num i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 

        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main()
{
    num t; cin>>t;

    while(t--)
    {
        num n; cin>>n; num a[n];

        for(num i=0; i<n; i++) cin>>a[i];

        cout<<maxSubArraySum(a,n)<<"\n";
    }

    return 0;
}