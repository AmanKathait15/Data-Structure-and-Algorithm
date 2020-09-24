#include<bits/stdc++.h>
using namespace std;

/*BLUE PRINT FOR GRAPH DATA STRUCTURE*/
class graphtype {

private:

	int source;
	int dest;
	int weight;
	graphtype *next;

	int getdest();
	void setdest(int);
	int getweight();
	void setweight(int);
	int getsource();
	void setsource(int);
	void setnext(graphtype*);
	graphtype* getnext();

public:

	void display_graph(graphtype *[], int );
	void input_graph(graphtype *[], int );
	void mst(graphtype *[], queue<int> ,int [], int);
	void find(int [],int , int );
	void setParent(int [], int);
	void showParent(int [],int );
};

void graphtype::setnext(graphtype *ptr)
{
	next = ptr;
}

graphtype* graphtype::getnext()
{
	return next;
}
void graphtype::setweight(int w)
{
	weight=w;
}

int graphtype::getweight()
{
	return weight;
}

void graphtype::setsource(int s)
{
	source=s;
}

int graphtype::getsource()
{
	return source;
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
	while(total_edge--)
	{
		int s,d,w;
		//printf("enter source and destination of edege %d: ",i++);
		scanf("%d%d",&s,&d,&w);

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

void graphtype::mst(graphtype *vertice[], queue<int> Queue,int parent[],int s)
{
	graphtype *ptr = vertice[s];

	printf("node processed id %d\n",s);

	while(ptr!=NULL)
	{
		int x = ptr->getdest();

		if(parent[x] == x)
		{
			parent[x] = s;
			Queue.push(x);
		}
		ptr=ptr->getnext();
	}

	//showParent(parent,6);

	if(!Queue.empty())
	{
		s = Queue.front();	Queue.pop();
		bfs(vertice,Queue,parent,s);
	}
}

void graphtype::setParent(int parent[], int v)
{
	for (int i = 0; i < v; ++i)
	{
		parent[i]=i;
	}
}

void graphtype::showParent(int parent[], int v)
{
	cout<<"\n";
	for (int i = 0; i < v; ++i)
		cout<<parent[i]<<" ";
	cout<<"\n";
}

void graphtype::find(int parent[], int s,int d)
{
	printf("shortest path : %d<--->",d);
	while(parent[d]!=s)
		printf("%d<--->",d=parent[d]);
	printf("%d\n",s);
}

int main()
{
	int v,e;
	cin>>v>>e;
	int parent[v],s,d;

	graphtype *vertice[v]={NULL},g;
	
	g.setParent(parent,v);
	g.input_graph(vertice,e);			//O(e)
	g.display_graph(vertice,v);		//O(v+e)

	queue<int> Queue;

	printf("Enter source and destination: ");
	scanf("%d%d",&s,&d);	parent[s]=-1;

	g.bfs(vertice,Queue,parent,s);
	g.find(parent,s,d);

	return 0;
}