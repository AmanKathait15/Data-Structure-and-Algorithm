#include<iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r, int i)  {  real = r;   imag = i; }
    Complex operator ++(int);
    Complex & operator ++();
    friend ostream & operator << (ostream &out, const Complex &c);

    //ostream & operator << (ostream &out, const Complex &c);

    /*cout is an object of ostream class which is a compiler defined class. When we do "cout << obj" where obj is an object of our class, 
    the compiler first looks for an operator function in ostream, then it looks for a global function*/

};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag;
    return out;
}

Complex &Complex::operator ++()
{
    ++real; ++imag; cout<<"prefix\n";
    //real++; imag++; cout<<"prefix\n";

    return *this;
}

Complex Complex::operator ++(int i) // prefix oveloaded operator has a dummy parametr to distinguish
{
    Complex c1(real, imag); cout<<"postfix\n";
    real++; imag++;
    return c1;
}

int main()
{
    Complex c1(10, 15);

    cout<<c1<<"\n";
    
    Complex tmp = c1++; 
    
    cout<<tmp<<"\n";
    
    tmp = ++c1;
    
    cout<<tmp<<"\n";

    return 0;
}