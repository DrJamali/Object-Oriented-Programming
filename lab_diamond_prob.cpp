#include <iostream>
using namespace std;

class Engine
{

public:
int a;
    virtual void start()
    {
        cout << "Engine start" << endl;
    }
};

class Car :virtual  public Engine
{
public:
int a;
    void start() override
    {
        cout << "Car start" << endl;
    }
};

class Bikes :virtual public Engine
{
public:
int a;
    void start() override
    {
        cout << "Bikes start" << endl;
    }
};

class HybridCar : public Car, public Bikes
{
public:
 void start() override{
     cout << "HybridCar start" << endl;
 }
   
};

int main()
{
    HybridCar car;
    car.start();
    return 0;
}
