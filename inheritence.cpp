#include <iostream>
#include <string.h>
using namespace std;

class students
{
    protected:
    string Name;
    string Father_name;
    int Age;

public: // this will allow us to use these blue prints in main function
    void setname(string name)
    {
        Name = name;
    }
    string getname()
    {
        return Name;
    }
    void setage(int age)
    {
        Age = age;
    }
    int getage()
    {
        return Age;
    }
    void about_yourself()
    {

        cout << "My name is " << Name << endl;
        cout << "My fatther name is " << Father_name << endl;
        cout << "I am " << Age << " old" << endl;
        cout << "Thank You!!" << endl;
    }
    students(string name, string fathername, int age)
    {
        Name = name;
        Father_name = fathername;
        Age = age;
    }
    void obey()
    {
        if (Age > 29)
        {
            cout << "You are a class member" << endl;
        }
        else
        {
            cout << "Sorry but go to hell" << endl;
        }
    }
};
class medical_st:public students{
    public:
    string field;
    medical_st(string name, string fathername,int age,string prof):
    students(name,fathername,age)
    {
        field = prof;
    }
    void introduction(){
        
        cout << "My name is " << Name << endl;
        cout << "My fatther name is " << Father_name << endl;
        cout << "I am " << Age << " old" << endl;
        cout<<"current i am working in "<<field <<endl; 
        cout << "Thank You!!" << endl;
    }
};
int main()
{
    medical_st s1 = medical_st("Hazrate jamali", "Sibghat Ullah", 128, "programming fundamenta");
    s1.introduction();

}