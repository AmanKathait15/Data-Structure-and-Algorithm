#include <bits/stdc++.h>
using namespace std;
#define num long int 

void lps(string str,num n)
{
    num start = 0,maxlength=1,low,high;

    for(num i=1; i<n; i++)
    {
        low = i-1; high = i;   // for even length palindrome

        while(low>=0 && high<n && str[low]==str[high])
        {
            num len = high-low+1; if(len>maxlength) { start = low; maxlength = len; } low--; high++;
        }

        low = i-1; high = i+1;  // for odd length palindrome

        while(low>=0 && high<n && str[low]==str[high])
        {
            num len = high-low+1; if(len>maxlength) { start = low; maxlength = len; } low--; high++;
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