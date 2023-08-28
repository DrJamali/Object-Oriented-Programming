#include <iostream>
using namespace std;
class vector
{
public:

    int n;
    int *arr;

    vector(int m)
    {
        n = m;
        arr = new int[m];
    }
    int dot_product(vector &v)
    {
        int d=0;
        for (int i = 0; i < n; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};
int main()
{
    vector v1(3);
    v1.arr[0] =1;
    v1.arr[1] =2;
    v1.arr[2] =3;
    vector v2(3);
    v2.arr[0] =1;
    v2.arr[1] =2;
    v2.arr[2] =3;
   cout<<v1.dot_product(v2)<<endl;

    return 0;
}