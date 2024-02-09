#include <iostream>
using namespace std;
class A{
    public:
    virtual void print(){
        cout<<"A"<<endl;
    }
};
class B:virtual public A{
    public:
    void print() override
    {
        cout<<"B"<<endl;
    }
};
class C:virtual public A{
    public:
    void print() override
    {
        cout<<"C"<<endl;
    }
};
class D:public B,public C{
    public:
    void print() override
    {
        cout<<"D"<<endl;
    }
    
};
int main() {
    D d;
    d.print();
    return 0;
}