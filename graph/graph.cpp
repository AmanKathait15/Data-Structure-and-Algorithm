#include<bits/stdc++.h>
using namespace std;

/*BLUE PRINT FOR GRAPH DATA STRUCTURE*/
class graphtype {

private:

	int dest;
	graphtype *next;

	int getdest();
	void setdest(int);
	void setnext(graphtype*);
	graphtype* getnext();

public:

	void display_graph(graphtype *[], int );
	void input_graph(graphtype *[], int );
};

void graphtype::setnext(graphtype *ptr)
{
	next = ptr;
}

graphtype* graphtype::getnext()
{
	return next;
}

void graphtype::setdest(int d)
{
	dest=d;
}

int graphtype::getdest()
{
	return dest;
}

void graphtype::input_graph(graphtype *vertice[], int total_edge)
{
	int i=1;
	while(i<=total_edge)
	{
		int s,d;
		printf("enter source and destination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		graphtype *ptr = new(graphtype);
		ptr->setdest(d);
		ptr->setnext(vertice[s]);
		vertice[s]=ptr;
	}
}

void graphtype::display_graph(graphtype *vertice[],int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		printf("vertice[%d]--->",i);
		while(ptr!=NULL)
		{
			printf("%d--->",ptr->getdest());
			ptr=ptr->getnext();
			e++;
		}	printf("NULL\n");
	}
}

int main()
{
	int v,e;
	cin>>v>>e;

	graphtype *vertice[v]={NULL},g;
	
	g.input_graph(vertice,e);			//O(e)
	g.display_graph(vertice,v);		//O(v+e)

	return 0;
}