#include <iostream>
using namespace std;
class Time{
private:
int time;
public:
Time (int a): time(a){}
void add_time(Time obj1,Time obj2){
    time= obj1.time+obj2.time;
}
void display(){
    cout<<time<<endl;
}
};
int main() {
    Time T1(5);
    Time T2(6);
    Time T3(7);
    
    T3.add_time(T1,T2);
    T3.display();
    return 0;
}