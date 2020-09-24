#include<bits/stdc++.h>
using namespace std;

stack<int> s1,s2;

void push1(int num)
{
	while(!s1.empty())
	{
		s2.push(s1.top()); s1.pop();
	}

	s2.push(num);

	while(!s2.empty())
	{
		s1.push(s2.top()); s2.pop();
	}
}

int pop1()
{
	int num = s1.top(); s1.pop();

	return num;
}

/// by making pop operation costly

void push(int num)
{
	 s1.push(num);
}

int pop()
{
	int num ;

	while(!s1.empty())
	{
		num =  s1.top();  s1.pop();

		if(!s1.empty())
		s2.push(num);
	}

	while(!s2.empty())
	{
		s1.push(s2.top()); s2.pop();
	}

	return num;
}

void display()
{
	stack<int> tmp =  s1;

	while(!tmp.empty())
	{
		cout<<tmp.top()<<" ";
		tmp.pop();
	}
}

int main()
{

	while(1)
	{
		char ch;	cout<<"enetr choice: "; cin>>ch;

		if(ch=='e') break;

		switch(ch)
		{
			case 'i': cout<<"enter number "; int num; cin>>num; push(num); break;
			case 'r': if( s1.empty())	cout<<"empty\n";
					  else
					  {
					  	cout<<pop()<<"\n";
					  } 
					  break;
			case 'd': if( s1.empty())	cout<<"empty\n"; else display(); break;
			default : exit(0);
		}
	}

	return 0;
}