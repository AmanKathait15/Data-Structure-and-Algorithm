#include<stdio.h>
#include<stdlib.h>
#define max 100
#define INT_MIN -9999999

typedef struct node
{
	int info;
	int prio;
} nodetype;

void insertMinHeap(nodetype minHeap[],int num,int prio, int now)
{
	while((minHeap[now/2].prio)>prio)
	{
		minHeap[now].prio = minHeap[now/2].prio;
		minHeap[now].info = minHeap[now/2].info;
		now/=2;
	}
	minHeap[now].prio=prio;
	minHeap[now].info=num;
}

int extractMinHeap(nodetype minHeap[])
{
	nodetype minElement = minHeap[1],lastElemnet=minHeap[(minHeap[0].info)--];
	int size=minHeap[0].info,now=1,child = 2*now;

	while(child<=size && lastElemnet.prio > minHeap[child].prio)
	{
		if((child+1)<=size && (minHeap[child+1].prio<minHeap[child].prio))
			child++;
		minHeap[now].prio=minHeap[child].prio;
		minHeap[now].info=minHeap[child].info;
		now = child;
		child = 2*now;
	}

	minHeap[now].prio = lastElemnet.prio;
	minHeap[now].info = lastElemnet.info;
	minHeap[size+1] = minElement;

	return minElement.info;
}

void display(nodetype minHeap[])
{
	for (int i = 1; i <=minHeap[0].info; ++i)
	{
		printf("priority : %d data : %d\n",minHeap[i].prio,minHeap[i].info);
	}
}

int main()
{
	nodetype minHeap[max]; int  ch,num,prio;	minHeap[0].info=0;	minHeap[0].prio=INT_MIN;
	
	while(1)
	{
		printf("\nenter choice 1: insert 2: serve 3: display 4: exit\n");	scanf("%d",&ch);
		system("clear");
		if(ch==1)
		{
			printf("enter number and its priority : ");
			scanf("%d%d",&num,&prio);

			(minHeap[0].info)++;
			insertMinHeap(minHeap,num,prio,minHeap[0].info);
		}
		else if(ch==2)
		{
			if(!minHeap[0].info)	printf("\nunderflow");
			else		printf("\nelement serve from priority queue is %d : ",extractMinHeap(minHeap));
		}
		else if(ch==3)
		{
			if(!minHeap[0].info)	printf("\nunderflow");
			else		display(minHeap);
		}
		else if(ch==4)	break;
		else printf("\ninvalid choice");
	}
}