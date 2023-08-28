#include <iostream>
using namespace std;
template <class T>
class vector
{
public:

    int n;
    T *arr;

    vector(int m)
    {
        n = m;
        arr = new T[m];
    }
    T dot_product(vector &v)
    {
        T d=0;
        for (int i = 0; i < n; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};
int main()
{
    vector<float>v1(3);
    v1.arr[0] =1.4;
    v1.arr[1] =3.3;
    v1.arr[2] =0.1;
    vector<float> v2(3);
    v2.arr[0] =0.1;
    v2.arr[1] =1.90;
    v2.arr[2] =4.1;
   cout<<v1.dot_product(v2)<<endl;

    return 0;
}