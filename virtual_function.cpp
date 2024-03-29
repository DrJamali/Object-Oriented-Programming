#include <iostream>
using namespace std;

class Base
{
    int val1;

public:

    Base()=default;
    Base(int a)
    {
        val1 = a;
    }
    int getter()
    {
        return val1;
    }
    void display()
    {
        cout << "Hello this is base class";
    }
};
class Derived : public Base
{
    int val2;

public:

    Derived()=default;
    Derived(int b)
    {
        val2 = b;
    }
    int getter()
    {
        return val2;
    }
    void display()
    {
        cout << "Hello this is derived class";
    }
};

int main()
{
    Base obj1(12);
    Base *bptr = &obj1;

    Derived obj2(15);
    Base *dptr = &obj2;

    bptr->display();
    dptr->display();


    return 0;
}