#include <iostream>
using namespace std;
template <class Gujjar>
class SUM
{
public:

    Gujjar sum(Gujjar num1,Gujjar num2){
        Gujjar sum = num1  num2;
        return sum;
    }    

};
int main()
{
    
   SUM<int> s1;
   cout<<s1.sum(12,13)<<endl;
   SUM<float> s2;
   cout<<s2.sum(12.5,13.5)<<endl;
   SUM<double> s3;
   cout<<s3.sum(12,13)<<endl;

    return 0;
}