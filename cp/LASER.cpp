#include<bits/stdc++.h>
using namespace std;
#define num unsigned long long int

struct Point 
{ 
    int x; 
    int y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(Point p, Point q, Point r) 
{  
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool collide(Point p1, Point q1, Point p2, Point q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 

    if (o1 != o2 && o3 != o4) 
        return true;  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false;
}

int main()
{
	num t;
	cin>>t;

	while(t--)
	{
		num n,q;
		cin>>n>>q;

		vector<Point> a(n+1);

		for(num i=1; i<=n; i++)
		{
			cin>>a[i].y; a[i].x=i;
		}
		for(num i=1; i<=n; i++)
		{
			cout<<a[i].x<<" "<<a[i].y<<"\n";
		}

		while(q--)
		{
			Point p1,p2; num count=0,x1,x2,y;
			cin>>x1>>x2>>y;
			p1.x=x1; p1.y=y; p2.x=x2; p2.y=y;

			for(num i=1; i<n; i++)
			{	
				if(collide(p1,p2,a[i],a[i+1]))	count++;
			}
			cout<<count<<"\n";
		}
	}
	return 0;
}