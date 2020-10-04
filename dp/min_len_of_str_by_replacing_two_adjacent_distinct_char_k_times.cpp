#include<bits/stdc++.h> 
using namespace std; 

int stringReduction(string str) 
{ 
	int n = str.length(); 

	int count[3] = {0}; 
	
	for (int i=0; i<n; ++i) count[str[i]-'a']++; 

	// If all characters are same. 
	if (count[0] == n || count[1] == n || count[2] == n) return n; 

	// If all characters are present even number 
	// of times or all are present odd number of 
	// times. 
	if ((count[0] % 2) == (count[1] % 2) && (count[1] % 2) == (count[2] % 2)) return 2; 

	// Answer is 1 for all other cases. 
	return 1; 
} 

int main() 
{ 
	string str; cin>>str; 
	cout << stringReduction(str); 
	return 0; 
} 
