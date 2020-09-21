#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node 
{
    int info;
    node *next;
};

void intersection(node **tail1, node **tail2)
{
    int num; cout<<"enter a number : "; cin>>num; size++;

    node *ptr = new node();

    ptr->info = num; ptr->next=NULL;

    (*tail1)->next = ptr;
    *tail1 = (*tail1)->next;

    (*tail2)->next = ptr;
    *tail2 = (*tail2)->next;
}

void push(node **head, node **tail)
{
    int num; cout<<"enter a number : "; cin>>num; size++;

    node *ptr = new node();

    ptr->info = num; ptr->next=NULL;

    if(*head == NULL)
    {
        *head = *tail = ptr;
    }
    else
    {
        (*tail)->next = ptr;
        *tail = (*tail)->next;
    }
}

void pop(node **head , node **tail)
{
    if(*head == NULL)   printf("empty \n");
    else
    {
        printf("%d \n",(*head)->info); *head=(*head)->next; size--;
    }

    if(*head==NULL) *tail = NULL;
}

void display(node *head)
{
    while(head)
    {
        printf("[%d]--",head->info); head=head->next;
    }   printf("NULL\n");
}

void find_intersection(node *head1,node* head2)
{
    map<node*,int> mp;

    while(head1 && head2)
    {
        mp[head1]++; mp[head2]++;
        head1=head1->next; head2=head2->next;
    }

    while(head1)
    {
        mp[head1]++;
        head1=head1->next;
    }

    while(head2)
    {
        mp[head2]++;
        head2=head2->next;
    }

    for(auto i=mp.rbegin(); i!=mp.rend(); i++)
    {
        node *head = i->first; 

        if(i->second == 1) break;

        printf("%d ",head->info);
    }   printf("\n");
}

int main()
{
    node *head1 = NULL , *tail1 = NULL , *head2 = NULL , *tail2 = NULL;

    while(1)
    {
        char ch; printf("i,r,d,I,F,e: "); cin>>ch;

        switch(ch)
        {
            case 'i': push(&head1,&tail1); break; 
            case 'p': push(&head2,&tail2); break;
            case 'r': pop(&head1,&tail1); break; 
            case 'P': pop(&head2,&tail2); break;
            case 'd': display(head1); display(head2); break;
            case 'I': intersection(&tail1,&tail2); break;
            case 'F': cout<<"common nodes are : "; find_intersection(head1,head2); break;
            case 'l': printf("%d\n",size); break;
            default: exit(0);
        }
    }

    return 0;
}