// C++ program to count inversions using Binary Indexed Tree 
#include<bits/stdc++.h> 
using namespace std;
#define num long long int

num query(vector<num> &bit,num i)
{
    num res = 0;    for(; i>0; i = i & (i-1))   res+= bit[i];       return res;
}

void update(vector<num> &bit,num n,num i,num val)  
{
    for(; i<=n; i+= i & (-i))   bit[i] += val;
} 

void display(vector<num> &a,num n)
{
    for(num i=1; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

num getInvCount(vector<num> &bit,num arr[], num n, num maxElement) 
{ 
    num invcount = 0;

    for (num i=n-1; i>=0; i--) 
    {  
        invcount += query(bit, arr[i]-1); 

        //display(bit,maxElement+1);

        //printf("(%d,%d) : %d\n",i,arr[i]-1,invcount);

        update(bit, maxElement, arr[i], 1);
    } 

    return invcount; 
} 

int main() 
{
    num t; cin>>t;

    while(t--)
    {
        num n,maxElement=0; cin>>n; num a[n];

        for(num i=0; i<n; i++) 
        {
            cin>>a[i]; if(a[i]>maxElement) maxElement = a[i];
        }

        vector<num> bit(maxElement+1);

        cout<<getInvCount(bit,a,n,maxElement)<<"\n";
    }
    
    return 0; 
} 