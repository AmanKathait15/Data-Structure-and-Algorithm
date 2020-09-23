#include<bits/stdc++.h>
using namespace std; 

string idToShortURL(long int n) 
{ 
	char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

	string shorturl=""; 

	while (n) 
	{ 
		//cout<<map[n%62]<<" "<<(n)<<"\n";
		shorturl+= map[n%62];	n = n/62; 
	} 

	reverse(shorturl.begin(), shorturl.end()); 

	return shorturl; 
} 

long int shortURLtoID(string shortURL) 
{ 
	long int id = 0; 

	for (int i=0; i < shortURL.length(); i++) 
	{ 
		if ('a' <= shortURL[i] && shortURL[i] <= 'z') 	id = id*62 + shortURL[i] - 'a'; 
		if ('A' <= shortURL[i] && shortURL[i] <= 'Z') 	id = id*62 + shortURL[i] - 'A' + 26; 
		if ('0' <= shortURL[i] && shortURL[i] <= '9') 	id = id*62 + shortURL[i] - '0' + 52; 
	} 

	return id; 
} 

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		int n; cin>>n;
		
		string shorturl = idToShortURL(n);

		cout << "Generated short url is " << shorturl << endl; 
		
		cout << "Id from url is " << shortURLtoID(shorturl);
	} 
	
	return 0; 
} 
