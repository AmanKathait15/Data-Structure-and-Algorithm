#include<bits/stdc++.h>
using namespace std;

queue<int> q1,q2;

void push1(int num)
{
	q2.push(num);

	while(!q1.empty())
	{
		q2.push(q1.front()); q1.pop();
	}

	queue<int> tmp = q1;
	q1 = q2; q2 = tmp;
}

int pop1()
{
	int num = q1.front(); q1.pop();

	return num;
}

/// by making pop operation costly

void push(int num)
{
	q1.push(num);
}

int pop()
{
	int num ;

	while(!q1.empty())
	{
		num = q1.front(); q1.pop();

		if(!q1.empty())
		q2.push(num);
	}

	queue<int> tmp = q1;
	q1 = q2; q2 = tmp;

	return num;
}

void display()
{
	queue<int> tmp = q1;

	while(!tmp.empty())
	{
		cout<<tmp.front()<<" ";
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
			case 'r': if(q1.empty())	cout<<"empty\n";
					  else
					  {
					  	cout<<pop()<<"\n";
					  } 
					  break;
			case 'd': if(q1.empty())	cout<<"empty\n"; else display(); break;
			default : exit(0);
		}
	}

	return 0;
}