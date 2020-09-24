/* Ds2namic Programming implementation of LCS problem */
#include <bits/stdc++.h> 
using namespace std; 
#define num int
#define N 100 

num L[N][N]; string s1,s2;

set<string> findLCS(num m, num n) 
{ 
	set<string> s; 

	if (m == 0 || n == 0) 
	{ 
		s.insert(""); 
		return s; 
	} 

	if (s1[m - 1] == s2[n - 1]) 
	{ 
	
		set<string> tmp = findLCS(m - 1, n - 1); 
 
		for (string str : tmp) 
			s.insert(str + s1[m - 1]); 
	} 

	else
	{ 
		if (L[m - 1][n] >= L[m][n - 1]) 
			s = findLCS(m - 1, n); 
 
		if (L[m][n - 1] >= L[m - 1][n]) 
		{ 
			set<string> tmp = findLCS(m, n - 1); 
			s.insert(tmp.begin(), tmp.end()); 
		} 
	} 
	return s; 
} 

num LCS(num m, num n) 
{ 
	for (num i = 0; i <= m; i++) 
	{ 
		for (num j = 0; j <= n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (s1[i - 1] == s2[j - 1]) 
				L[i][j] = L[i - 1][j - 1] + 1; 
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
	return L[m][n]; 
} 

num main() 
{
	cin>>s1>>s2;

	num n,m;
	if(s1.length()<s2.length())
	{
		n=s1.length(); m=s2.length();
	}else
	{
		n=s2.length(); m=s1.length();
		string tmp = s1; s1=s2; s2=tmp;
	}

	cout << "LCS length is " << LCS(m,n) << endl; 

	set<string> s = findLCS(m, n); 

	for (string str : s) 
		cout << str << endl; 

	return 0; 
} 
