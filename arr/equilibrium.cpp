#include <bits/stdc++.h>
using namespace std;

int equilibrium(int a[],int ps[], int n)
{
    int i=0,j=n-1,sum = ps[n-1],ans=-1;
    
    while(i<j)
    {
        int mid = i+j/2;

        if(mid == 0 || mid == n-1) break;

        if(ps[mid-1]==(sum-ps[mid]))
        {
        	ans = mid; break;
        }
        else if(ps[mid-1]>(ps[j]-ps[mid]))	j=mid-1;
        else	i=mid+1;
    }

    return ans==-1?ans:ans+1;
}

int main() {
	//code
	
	int t; cin>>t;
	
	while(t--)
	{
		int n; cin>>n; int a[n],ps[n],sum=0;
		
		for(int i=0; i<n; i++)
		{
		    cin>>a[i]; sum+=a[i]; ps[i]=sum;
		}
			
		cout<<equilibrium(a,ps,n)<<"\n";
	}
	return 0;
}