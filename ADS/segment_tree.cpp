#include<bits/stdc++.h>
using namespace std;

int cst(int a[],int l,int r,int *stp,int i)
{
	if(l==r)
	{
		stp[i] = a[r]; return a[r];
	}
	int mid = (l+r)/2;

	stp[i] = cst(a,l,mid,stp,i*2+1) + cst(a,mid+1,r,stp,i*2+2);

	return stp[i];
}

void display(int *stp,int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d ",*(stp+i));
	}	printf("\n");
}

int * constuct(int a[],int n)
{
	//find hegiht 
	int h = (int)(ceil(log2(n)));

	//find size 
	int size = 2*(int)pow(2,h)-1;

	int *stp = new int[size];

	cst(a,0,n-1,stp,0);

	display(stp,size);

	return stp;
}

int getSum(int *stp, int ss, int se, int qs, int qe, int i) 
{  
    if (qs <= ss && qe >= se)
    {
    	printf("%d,%d : %d : [%d,%d]\n",qs,qe,stp[i],ss,se);	return stp[i]; 
    }

    if (se < qs || ss > qe) 
    {
    	printf("%d,%d : %d : [%d,%d]\n",qs,qe,stp[i],ss,se); return 0;
    }
 
    int mid = (ss+se)/2;

    int sum = getSum(stp, ss, mid, qs, qe, 2*i+1) + getSum(stp, mid+1, se, qs, qe, 2*i+2);

    printf("%d,%d : %d : [%d,%d]\n",qs,qe,sum,ss,se);

    return sum;
} 

int main()
{
	int n; cin>>n; int a[n];

	for(int i=0; i<n; i++) cin>>a[i];

	int *stp = constuct(a,n);

	while(1)
	{
		int l,r; cin>>l>>r;

		cout<<getSum(stp,0,n-1,l,r,0)<<"\n";
	}

	return 0;
}