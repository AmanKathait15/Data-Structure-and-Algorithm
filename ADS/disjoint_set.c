#include<stdio.h>
#include<stdlib.h> // for malloc
#define max 100

typedef struct node {

	int source;
	int dest;
	int weight;
	struct node *next;

} graphtype;

//global variable easy to access and modify
graphtype *beg=NULL,*end=NULL;

int parent[max]={0};

int find(int i)
{
	while(i!=parent[i])
		i=parent[i];
	return i;
}

int Union(int s,int d)
{
	int i=find(s),j=find(d);
	
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else return 0;
}

int mst(int v)
{
	graphtype *root = beg,*tmp; int total_weight = 0;

	while(v)
	{
		int s=root->source,d=root->dest,w=root->weight;

		if(Union(s,d))	// if no cycle formed
		{
			total_weight+=w;
			v--;
			tmp=root;
		}
		else tmp->next=root->next;
		root=root->next;

		/*for (int i = 0; i < v; ++i)
		{
			printf("%d ",parent[i]);
		}	printf("\n");*/
	}	tmp->next=NULL;

	return total_weight;
}

void create_edge(int s,int d,int w)
{
	graphtype *ptr = (graphtype*)malloc(sizeof(graphtype));
	ptr->source=s;
	ptr->dest=d;
	ptr->weight=w;
	ptr->next = beg;

	if(beg==NULL)
	{
		beg=end=ptr;
	}
	else
	{
		if(w < (beg->weight))
		beg=ptr;
		else if(w>(end->weight))
		{
			end->next=ptr;	end=ptr;	ptr->next=NULL;
		}
		else
		{
			graphtype *tmp=beg;
			while(w>(tmp->next)->weight)
			tmp=tmp->next;
			ptr->next=tmp->next;
			tmp->next=ptr;
		}
	}
}

void input_graph(int total_edge)
{
	int i=1;
	while(total_edge--)
	{
		int s,d,w;
		//printf("enter source destination and weight of edege %d: ",i++);
		scanf("%d%d%d",&s,&d,&w);

		create_edge(s,d,w);
	}
}

void display_graph()
{
	graphtype *tmp=beg;
	printf("edege list in ascending order of weights: \n");

	while(tmp!=NULL)
	{
		printf("[%d|%d|%d]--->",(tmp->source),(tmp->dest),(tmp->weight) );
		tmp=tmp->next;
	}	printf("NULL\n");
}

int main()
{
	int v,e; graphtype *beg=NULL;

	//printf("enter total number of vertices and edges: ");
	scanf("%d%d",&v,&e);

	for (int i = 1; i < v; ++i)
	{
		parent[i] = i;
	}

	input_graph(e);			//O(e)
	display_graph();		//O(v+e)

	printf("minimum weight = %d\n",mst(v-1));

	display_graph();		//O(v+e)
}