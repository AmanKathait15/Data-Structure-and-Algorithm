#include<bits/stdc++.h>
using namespace std;

int min_platform(int arr[], int dep[], int n)
{
    int m=0,i=0,j=0,c=0;

    sort(arr,arr+n);
    sort(dep,dep+n);

    while(i<n && j<n)
    {
        if(arr[i]<dep[j])
        {
            c++; i++;
        }
        else if(arr[i]>dep[j])
        {
            c--; j++;
        }

        if(c>m) m=c;
    }

    return m;
}

int main()
{
    int n; cin>>n; int arr[n],dep[n];

    for(int i=0; i<n; i++)
        cin>>arr[i]>>dep[i];

    cout<<min_platform(arr,dep,n)<<"\n";

    return 0;
}