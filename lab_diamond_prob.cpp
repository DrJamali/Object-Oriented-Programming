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

class Car :  public Engine
{
public:
int a;
    void start() override
    {
        cout << "Car start" << endl;
    }
};

class Bikes : public Engine
{
public:
int a;
    void start() override
    {
        cout << "Bikes start" << endl;
    }
};

class HybridCar :virtual public Car,virtual public Bikes
{
public:
//  void start() override{
//      cout << "HybridCar start" << endl;
//  }
   
};

int main()
{
    HybridCar car;
    car.Bikes::start();
    return 0;
}
