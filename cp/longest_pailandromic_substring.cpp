#include <bits/stdc++.h>
using namespace std;
#define num long num
#define size 100

static num lps[size][size];

num lps(string &s) 
{ 
    num n = s.length(); 
  
    // a[i] is going to imstore length of longest 
    // palindromic subsequence of substring s[0..i] 
    num a[n]; 
  
    // Pick starting ponum 
    for (num i = n - 1; i >= 0; i--) { 
  
        num back_up = 0; 
          
  
        // Pick ending ponums and see if s[i] 
        // increases length of longest common 
        // subsequence ending with s[j]. 
        for (num j = i; j < n; j++) { 
  
            // similar to 2D array L[i][j] == 1 
            // i.e., handling substrings of length 
            // one. 
            if (j == i) 
                a[j] = 1;  
  
            // Similar to 2D array L[i][j] = L[i+1][j-1]+2 
            // i.e., handling case when corner characters 
            // are same.  
            else if (s[i] == s[j]) 
            { 
                  
                // value a[j] is depend upon previous  
                // unupdated value of a[j-1] but in  
                // previous loop value of a[j-1] is  
                // changed. To store the unupdated  
                // value of a[j-1] back_up variable  
                // is used. 
                num temp = a[j]; 
                a[j] = back_up + 2; 
                back_up = temp; 
            } 
  
            // similar to 2D array L[i][j] = max(L[i][j-1], 
            // a[i+1][j]) 
            else
            { 
                back_up = a[j]; 
                a[j] = max(a[j - 1], a[j]); 
            } 
        } 
    } 
      
    return a[n - 1]; 
} 


num main() {
   
    num n;
    cin>>n;

    string str;
    cin>>str;

    LPS(str,n);
    return 0;
}