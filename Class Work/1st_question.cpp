#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual int area()  = 0;
    virtual int perimeter()  = 0;
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    int area()  override {
        return M_PI * radius * radius;
    }

    int perimeter()  override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    int area()  override {
        return length * width;
    }

    int perimeter()  override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    int side1, side2, side3;

public:
    Triangle(int s1, int s2, int s3) : side1(s1), side2(s2), side3(s3) {}

    int area()  override {
        int s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    int perimeter()  override {
        return side1 + side2 + side3;
    }
};

int main() {
    // Create an array of shapes
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4, 6),
        new Triangle(3, 4, 5)
    };
    for ( auto shape : shapes) {
        cout << "Area: " << shape->area() << " and Perimeter: " << shape->perimeter() << endl;
    }

    return 0;
}
