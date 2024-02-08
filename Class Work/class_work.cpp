#include <iostream>
#include <vector>
using namespace std;
class Reziseable{
    public:
    virtual void resize()=0;
};
class Shape
{
public:
int len;
int hei;
    virtual int area() = 0;
};
class Circle : public Shape , public Reziseable
{
public:
    int area()
    {
        return 3.14*(len/2) * (len/2);
    }
    void resize(){
        cout<<"Enter the length of the circle: ";
        cin>>len;
        cout<<"Enter the height of the circle: ";
        cin>>hei;
    }
};
class Rectangle : public Shape , public Reziseable
{
public:
    int area()
    {
        return 2*len*hei;
    }
    void resize(){
        cout<<"Enter the length of the rectangle: ";
        cin>>len;
        cout<<"Enter the height of the rectangle: ";
        cin>>hei;
    }
};
class Triangle:public Shape, public Reziseable{
    
    public:
    int area(){
        return (1/2 * len * hei);
    }
    void resize(){
        cout<<"Enter the length of the triangle: ";
        cin>>len;
        cout<<"Enter the height of the triangle: ";
        cin>>hei;
    }
};
class Shapelist
{
public:
    vector<Shape *> shapes;
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
    Circle c1;
    c1.area();
    c1.resize();
    Shapelist S1;
    S1.shapes.push_back(shape);
    S1.shapes.push_back(shape2);
    S1.calculate_area();

    return 0;
}