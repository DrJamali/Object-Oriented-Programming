#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Shape{
    public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape{
    private:
    float radius;
    public:
    Circle() : radius(0){};
    Circle(float r) : radius(r) {};
    double area() override
    {
        return (M_PI*radius*radius);
    }
    double perimeter() override{
        return (2*M_PI*radius);
    }
};

class Rectangle : public Shape{
    private:
    float length;
    float width;
    public:
    Rectangle(): length(0), width(0) {};
    Rectangle(float l, float w): length(l), width(w) {};
    double area()
    {
        return (length*width);
    }
    double perimeter()
    {
        return (2*(length+ width));
    }
};

class Triangle : public Shape{
    private:
    float length1;
    float length2;
    float height;
    float base;
    public:
    Triangle() : length1(0), length2(0), height(0), base(0) {};
    Triangle(float l1, float l2, float h, float b) : length1(l1), length2(l2), height(h), base(b) {};

    double area()
    {
        return (0.5 * base * height);
    }
    double perimeter()
    {
        return (length1 + length2 + height);
    }
};

int main()
{
    int max_shapes=3;
    int *ptr = new int[3];
    Shape **shapes= new Shape*[max_shapes];
    shapes[0] = new Circle(19);
    shapes[1] = new Rectangle(10, 15);
    shapes[2] = new Triangle(2,3,4,5);

    for(int i = 0; i < max_shapes; i++)
    {
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
    }
}