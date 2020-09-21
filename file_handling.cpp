#include<bits/stdc++.h> 
//#include<fstream>
using namespace std; 

int main() 
{
	ofstream c ("c.txt"),cpp ("cpp.txt"),cs ("cs.txt"); ifstream in ("test.txt");

	string line;

	while(in)
	{
		getline(in,line);

		if(line[line.length()-1]=='c')	c<<line<<"\n";
		else if(line[line.length()-1]=='p') cpp<<line<<"\n";
		else cs<<line<<"\n";
	}

	return 0; 
} 
