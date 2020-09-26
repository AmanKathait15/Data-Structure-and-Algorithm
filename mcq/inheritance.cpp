#include<iostream>
using namespace std;
 
class base {
    int arr[10];
};
 
class b1: public base { };
 
class b2: public base { };
 
class derived: public b1, public b2 {};
 
int main(void)
{
  cout << sizeof(base);
  cout << sizeof(b1);
  cout << sizeof(b2);
  cout << sizeof(derived); // wastage of memory as two copy of base class and also leads to ambiguity 
  return 0;
}