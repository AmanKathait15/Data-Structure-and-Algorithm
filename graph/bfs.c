//breadth first search to find shortest path between two connected nodes
#include<stdio.h>
#include<stdlib.h> // for malloc
#define max 100

typedef struct node {

	int dest;
	struct node *next;
} graphtype;

//global variable easy to access and modify
graphtype *vertice[max],*front=NULL,*rear=NULL;

int parent[max],count=0;

void find(int i)
{
	printf("%d-->",i);
	while(parent[i]!=-1)
	{
		i=parent[i];
		printf("%d-->",i);
	}	printf("\n");
}

void insert(int num)
{
	graphtype *ptr;

	ptr = (graphtype*)malloc(sizeof(graphtype));
	ptr->dest=num;
	ptr->next=NULL;

	if(rear==NULL)
	front=rear=ptr;
	else
	{
		rear->next=ptr;	rear=ptr;
	}	
}

int serve()
{
	graphtype *ptr=front; int num = ptr->dest;
	front=front->next;
	free(ptr);
	if(front==NULL)	
	rear=NULL;
	return num;
}

void display()
{
	graphtype *tmp = front;
	while(tmp!=NULL)
	{
		printf("%d-->",tmp->dest);	tmp=tmp->next;
	}
}

void bfs(int s)
{
	graphtype *ptr = vertice[s];

	while(ptr!=NULL)
	{
		if(parent[ptr->dest]==ptr->dest)
		{
			parent[ptr->dest] = s;
			insert(ptr->dest);
		}
		ptr=ptr->next;
	}
	//display();

	//for(int i=0; i<6; i++)
	//	printf("%d ",parent[i]);

	if(front!=NULL)
	bfs(serve());
	
}

void create_edge(int s,int d)
{
	graphtype *ptr = (graphtype*)malloc(sizeof(graphtype));
	ptr->dest=d;
	ptr->next = vertice[s];
	vertice[s]=ptr;
}

void input_graph(int total_edge)
{
	int i=1;
	while(total_edge--)
	{
		int s,d;
		//printf("enter source and destination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		create_edge(s,d);
	}
}

void display_graph(int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		printf("\nedge %d: ",i);
		while(ptr!=NULL)
		{
			printf("-->%d",ptr->dest);
			ptr=ptr->next; e++;
		}
	}
}
void set_parent(int v)
{
	for (int i = 0; i<v; ++i)
	parent[i]=i;
}
void show_parent(int v)
{
	printf("\n");
	for (int i = 0; i<v; ++i)
	printf("%d ",parent[i]);	
}

void path(int v)
{
	for (int i = 0; i<v; ++i)
	{
		find(i);
	}
}

int main()
{
	int v,e,s,d;

	//printf("enter total number of vertices and edges: ");
	scanf("%d%d",&v,&e);

	input_graph(e);			//O(e)
	display_graph(v);		//O(v+e)

	for (int i = 0; i<v; ++i)
	{
		set_parent(v);
		parent[i]=-1;

		bfs(i);
		//show_parent(v);
		path(v);
	}
}