#include<iostream>
using namespace std;
 
class Base
{
//private:
protected:
    
    int a;

public:
    
    Base() {a = 0;}
};
//class Derived1: virtual public Base
class Derived1:  public Base
{

public:
    
    int c;
};
 
//class Derived2: virtual public Base
class Derived2:  public Base
{

public:
    
    int c;
};
 
class DerivedDerived: public Derived1 , public Derived2
{

public:

    void show()  {   cout << a;  } // there are two copies of 'a' in DerivedDerived which makes the statement "cout << a;" ambiguous
    //void show1()  {   cout <<Derived2::a;  }
    //void show2()  {   cout <<Derived1::a;  }
};
 
int main(void)
{
    DerivedDerived d;
    
    d.show();
    //d.show1();
    //d.show2();
    
    return 0;
}