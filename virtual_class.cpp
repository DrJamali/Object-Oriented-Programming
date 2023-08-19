#include <iostream>
using namespace std;
class Student
{
protected:
    string name;
    int roll_number;

public:
    void set_values(string n, int roll)
    {
        name = n;
        roll_number = roll;
    }
    void get_values()
    {
        cout << "Name = " << name << endl
             << "Roll number = " << roll_number<<endl;
    }
};
class Marks : virtual public Student
{
protected:
    int physics;
    int chemistry;
    int biology;

public:
    void set_marks(int p, int c, int b)
    {
        physics = p;
        chemistry = c;
        biology = b;
    }
};
class Score : virtual public Student
{
protected:
    int score;

public:
    void set_score(int sc)
    {
        score = sc;
    }
    void get_score(){
        cout<<"Score is "<<score<<endl;
    }
};

class Result : public Score, public Marks
{
    int total;
    public:
    void display(){
        total = score + physics + chemistry + physics;
        cout<<"Your result is "<<total<<endl;
    }
};

int main()
{
Result sibi;
sibi.set_values("H.Sibghat Ullah", 25);
sibi.set_marks(8,9,10);
sibi.set_score(8);
sibi.get_values();
sibi.get_score();
sibi.display();


    return 0;
}