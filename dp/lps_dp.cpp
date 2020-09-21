#include <bits/stdc++.h>
using namespace std;
#define num long int

void lps(string str,num n)
{
    bool dp[n][n]; memset(dp,0,sizeof(dp)); num start = 0 , maxlength = 1;

    for(num i=0; i<n; i++)              //plaindrome of length 2
    {
        dp[i][i]=1;   //plaindrome of length 1

        if(str[i] == str[i+1])
        {
           dp[i][i+1]=1; if(maxlength<2) { start = i; maxlength = 2; }
        }
    }

    for(num k=3; k<n; k++)
    {
        for(num i=0; i<n-k+1; i++)
        {
           num j = i+k-1;   //printf("(%d,%d,%d) : %d\n",i,j,k,(dp[i+1][j-1] && str[i]==str[j]));

           if(dp[i+1][j-1] && str[i]==str[j])
           {
              dp[i][j] =1; if(k>maxlength) { start = i; maxlength = k; } 
           }
        }
    }

    cout<<str.substr(start,maxlength)<<"\n";
}

int main() {
  
  num t; cin>>t;
  
  while(t--)
  {
      string str; cin>>str; lps(str,str.length());
  }
  return 0;
}