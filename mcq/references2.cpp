#include<iostream>
using namespace std;
 
int &fun()
{
    static int x = 10;	// chage the scope of x because static variable are stored in data segment
    return x;
}
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}