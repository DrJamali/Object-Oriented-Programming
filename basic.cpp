#include<iostream>
using namespace std;
// in this code we will learn about  public private and attributes and behaviours
class students{
    public: //this will allow us to use these blue prints in main function
    string name;
    string father_name;
    int age;

    void about_yourself(){

        cout<<"My name is "<<name<<endl;
        cout<<"My fatther name is"<<father_name<<endl;
        cout<<"I am "<<age<<" old"<<endl;
        cout<<"Thank You!!"<<endl;
    }
};
int main(){

students s1;
s1.name = "Gabriel";
s1.age = 18;
s1.father_name= "John malik";

students s2;
s2.name ="Hazrate Jamali";
s1.age =120;
s1.father_name ="H.Sibghat Ullah";

s1.about_yourself();
s2.about_yourself();
}