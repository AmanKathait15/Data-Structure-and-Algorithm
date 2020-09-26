#include<iostream>
using namespace std;
 
class base {
  int arr[10];     
};
 
class b1: virtual public base 
{

};
 
class b2: virtual public base
{

};
 
class derived: public b1, public b2
{
	
};
 
int main(void)
{ 

  derived d;

  cout<<sizeof(base)<<"\n";
  cout<<sizeof(b1)<<"\n";	// +8 for vptr
  cout<<sizeof(b2)<<"\n";	// +8 for vptr
  cout<<sizeof(derived)<<"\n"; // +16 for 2 base class vptr
  cout<<sizeof(d)<<"\n";
  //cout<<sizeof(d.arr);

  return 0;
} 