#include<bits/stdc++.h>
using namespace std;
#define num long int

void findLongestPalindromicString(string text,num N) 
{ 
  
    N = 2*N + 1; num LPS[N]; LPS[0] = 0; LPS[1] = 1; 

    num C = 1 , R = 2 , i = 0 , maxLPSLength = 0 ,maxLPSCenterPosition = 0 , start = -1 , end = -1; 

    for (i = 2; i < N; i++) 
    {
        num iMirror = 2*C-i , expand = 0 , diff = R - i; 

        if(diff >= 0) 
        {
            if(LPS[iMirror] < diff) LPS[i] = LPS[iMirror];
            else if(LPS[iMirror] == diff && R == N-1) LPS[i] = LPS[iMirror];
            else if(LPS[iMirror] == diff && R < N-1) // Case 3 
            { 
                LPS[i] = LPS[iMirror]; 
                expand = 1; // expansion required 
            } 
            
            else if(LPS[iMirror] > diff) // Case 4 
            { 
              LPS[i] = diff; 
              expand = 1; // expansion required 
            } 
        }
        else
        { 
          LPS[i] = 0; 
          expand = 1; // expansion required 
        } 
        if (expand == 1) 
          while (((i + LPS[i]) < N && (i - LPS[i]) > 0) && ( ((i + LPS[i] + 1) % 2 == 0) || (text[(i + LPS[i] + 1)/2] == text[(i-LPS[i]-1)/2] )))
            LPS[i]++;  

        if(LPS[i] > maxLPSLength) // Track maxLPSLength 
        { 
          maxLPSLength = LPS[i];    maxLPSCenterPosition = i; 
        } 

        if (i + LPS[i] > R) 
        { 
          C = i; 
          R = i + LPS[i]; 
        }
    } 

    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    end = start + maxLPSLength - 1; 

    cout<<text.substr(start,end-start+1)<<"\n";
} 

int main() 
{  
  string str; cin>>str;
  findLongestPalindromicString(str,str.length()); 
  return 0; 
} 
