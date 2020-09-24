#include<bits/stdc++.h>
using namespace std;

stack<int> s1,s2; int minEle = 0;

void push(int num)
{
	 if(s1.empty())
	 {
	 	s1.push(num); minEle = num;
	 }
	 else
	 {
	 	if(num<minEle)
	 	{
	 		minEle = num; s1.push(2*minEle-num);
	 	}
	 }
}

int pop()
{
	int num = s1.top(); s1.pop();

	if(num<minEle)
	{
		minEle = 2*minEle - num;
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
			case 'm': cout<<minEle<<" "; break;
			default : exit(0);
		}
	}

	return 0;
}