#include <iostream>
using namespace std;
 class test{
    int val1;
    public:
    int getdata(){
        return val1;
    }
    void setdata(int a){
        val1=a;
    }

 };

int main() {

 test t1;
 test *ptr = &t1;
 //Here we are making a pointer of t1 object remember pointer type should be same as the bject type
 (*ptr).setdata(7);
 //We can also call be this metthod

 cout<<ptr->getdata()<<endl;

 // use of new key word;
 test *ptr2 = new test;
 ptr2->setdata(5);

//  test h = new test;
// this doest not work a class can not be in a variable

// we can also initialize arrays by new keyword
test *ptr3 = new test[4];
ptr3->setdata(9);
//if we add +1 in ptr 3 it will now direct to the second object
ptr3++;
cout<<ptr3->getdata()<<endl;

    return 0;
}