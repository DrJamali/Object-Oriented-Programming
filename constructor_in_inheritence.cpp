#include <iostream>
using namespace std;

class Base1
{
protected:
    int val1;

public:
    Base1(int a)
    {
        val1 = a;
    }
};
class Base2
{
protected:
    int val2;

public:
    Base2(int b)
    {
        val2 = b;
    }
};
class derived : public Base1, public Base2
{
protected:
    int val3;

public:
    derived(int a, int b, int c) : Base1(a), Base2(b)
    {
        val3 = c;
    }
    void display()
    {

        cout << "Value 1 is " << val1 << endl
             << "Value 2 is " << val2 << endl
             << "Value 3 is " << val3 << endl;
    }
};

int main()
{
    derived test1(9,8,7);
    test1.display();
    return 0;
}