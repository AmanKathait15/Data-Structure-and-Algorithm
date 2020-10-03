#include<iostream>
using namespace std;
 
class Base
{
public:
    void fun()  { cout << "Base::fun() called"; }
    void fun(int i)  { cout << "Base::fun(int i) called"; }
};
 
class Derived: public Base
{
public:
    void fun() {  cout << "Derived::fun() called"; }
};
 
int main()
{
    Derived d;
    
    d.fun();
    
    //d.fun(5); // compiler error 
    
    /*If a derived class writes its own method, then all functions of base class with same name become hidden, even if signaures of 
    base class functions are different. In the above question, when fun() is rewritten in Derived, it hides both fun() and fun(int) 
    of base class.*/

    d.Base::fun(5);	//We can access base class functions using scope resolution operator even if they are made hidden by a derived class function.
    
    return 0;
}