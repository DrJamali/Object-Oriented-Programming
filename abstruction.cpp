#include <iostream>
#include <string.h>
using namespace std;

class rules
{
    virtual void obey() = 0;
};

class students : rules
{
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
int main()
{
    students s1 = students("Hazrate Jamali", "Sibghat Ullah", 118);
    students s2 = students("Hafiz Sibghat Ullah", "Chaudhary Attaullah", 22);
    s1.obey();
    s2.obey();
}