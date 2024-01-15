#include <iostream>
using namespace std;
class A{
public:
int a;
};
class B: public A{

};
class C: public B{

};
int main() {
    C c;
c.a = 1;
    return 0;
}