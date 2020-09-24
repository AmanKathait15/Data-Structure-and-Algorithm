#include<bits/stdc++.h>
using namespace std;
#define num long int

num bit_score(num n)
{
	num a=n%10,b=n/100,c=(n%100)/10,x,y,ans=0;

	x = max(a,b); x = max(x,c);
	y = min(a,b); y = min(y,c);

	ans = (11*x)+(7*y);
	ans = (ans % 100 )/ 10;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	num n,ans=0; cin>>n;

	num a[n],odd[10]={0},even[10]={0};

	for(num i=0; i<n; i++)
	{
		cin>>a[i]; a[i] = bit_score(a[i]);

		if(i%2==0)
			odd[a[i]]++;
		else
			even[a[i]]++;
	}

	for(num i=0; i<10; i++)
	{
		if(odd[i]==2) ans++;
		if(odd[i]>2) ans+=2;
		if(even[i]==2) ans++;
		if(even[i]>2) ans+=2;
	}

	cout<<ans<<"\n";

	return 0;
}