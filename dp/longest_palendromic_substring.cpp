#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
  int l = str.length();

  for(int i=0,j=l-1; i<j; i++,j--)
  {
    if(str[i]!=str[j]) return 0;
  }

  return 1;
}

string lps(string str,int l)
{
    for(int i=l-1; i>=0; i--)
    for(int j=0; j<=l-i; j++)
    {
        string sub = str.substr(j,i); //cout<<sub<<" ";

        if(isPalindrome(sub)) return sub;
    }

    return "";
}

int main() {
  
  int t; cin>>t;
  
  while(t--)
  {
      string str; cin>>str;

      if(isPalindrome(str)) cout<<str<<"\n";
      else cout<<lps(str,str.length())<<"\n";
  }

  return 0;
}