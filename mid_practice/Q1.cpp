#include <iostream>
using namespace std;
class mother{
    public:
    void display(){
        cout<<"I am mother"<<endl;
    }
};
class father
{
    public:
    void display(){
        cout<<"I am father"<<endl;
    }

};
class daughter : public father, public mother{
    public:
   
};
int main() {
    daughter d1;
    d1.father::display();
    d1.mother::display();

        return 0;
}