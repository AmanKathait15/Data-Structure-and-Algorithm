#include<bits/stdc++.h>
using namespace std;

stack<int> s,smin,smax;

int get_min()
{
	return smin.top();
}

int get_max()
{
	return smax.top();
}

void push(int num)
{
	if(s.empty())
	{
		s.push(num); smin.push(num); smax.push(num);
	}
	else
	{
		s.push(num);

		int min = smin.top() , max = smax.top();
		
		if(num<min)
			smin.push(num);
		else	smin.push(min);

		if(num>max)
			smax.push(num);
		else	smax.push(max);
	}
}

int pop()
{
	int num = s.top();

	s.pop(); smin.pop(); smax.pop();

	return num;
}

void display()
{
	stack<int> tmp = s;

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
			case 'r': if(s.empty())	cout<<"empty\n";
					  else
					  {
					  	cout<<pop()<<"\n";
					  } 
					  break;
			case 'd': if(s.empty())	cout<<"empty\n"; else display(); break;
			case 'm': cout<<"min: "<<get_min()<<"\n"; break;
			case 'M': cout<<"max: "<<get_max()<<"\n"; break;
			default : exit(0);
		}
	}

	return 0;
}