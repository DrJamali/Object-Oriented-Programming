#include<iostream>
using namespace std;

class simpleCalculator{
    protected:
    int val1;
    int val2;
    public:
    void setValue(int a, int b){
        val1 =a;
        val2 =b;
    }
    int add(){
        return (val1+val2);
    }
     int substract(){
        return (val1-val2);
    }
       int multiply(){
        return (val1*val2);
    }
       int divide(){
        return (val1/val2);
    }
};
class scientificCalculator : public simpleCalculator{
    public:
    int modulo(){
        return (val1%val2);
    }
    int percentage(){
        return (val1/val2 *100);
    }
};

class hybridcalculator :public scientificCalculator{
    public:
    void display(){
        cout<<add()<<endl;
    }
};
int main(){

hybridcalculator h1;
h1.setValue(100,2000);
h1.display();

    return 0;
} 