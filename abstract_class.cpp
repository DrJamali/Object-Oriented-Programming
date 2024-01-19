#include <iostream>
#include <vector>
using namespace std;
class Shape
{
public:
int len;
int hei;
    virtual int area() = 0;
    virtual int  return_len(){
        cout<<"I am Parent Shape"<<endl;
    }
};
class Circle : public Shape
{
public:
    int area()
    {
        return len*hei;
    }
    virtual int  return_len(){
        cout<<"I am circle"<<endl;
    }
};
class Rectangle : public Shape
{
public:
    int area()
    {
        return len*hei;
    }
};
class Shapelist
{
public:
    Shape* shapes[100];
    void calculate_area()
    {
        int total_area=0;
        for (auto x : shapes)
        {
            total_area=total_area+ x->area(); //calculating area of each shape 
        }
        cout<<"Area: "<<total_area<<endl;
    }
};
int main(){
    Shape* shape = new Circle;
    shape->len=5;
    shape->hei=5;
    Shape* shape2 = new Rectangle;
    shape2->len=5;
    shape2->hei=5;
    Shapelist S1;
    S1.shapes[0]=shape;
    S1.shapes[1]=shape2;
    S1.calculate_area();
    int arr[10];
    for(int x:arr){
        cout<<x;
    }
    Shape* square= new Circle;
    square->return_len();
    return 0;
}