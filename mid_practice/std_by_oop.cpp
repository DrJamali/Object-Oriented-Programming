#include <iostream>
#include <math.h>
using namespace std;
class inputs
{
protected:
    int size;
    int *arr;

public:
    inputs(int a, int arr2[])
    {
        size = a;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr2[i];
        }
    }

    int *arr_return()
    {
        return arr;
    }
};
class calculate : public inputs
{
private:
    int mean()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + arr[i];
        }
        cout << "Mean is " << sum / size << endl;
        return sum / size;
    }
    int deviation()
    {
        int cal_mean = this->mean();
        for (int i = 0; i < size; i++)
        {
            arr[i] = cal_mean - arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            cout << "After deviation values are " << arr[i] << endl;
        }
    }

    int variance()
    {
        int cal_mean = this->mean();
        this->deviation();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + pow(arr[i], 2);
        }
        cout << "Now sum = " << sum << endl;
        cout << "the varience is" << sum / cal_mean << endl;
        return sum / cal_mean;
    }

public:
    calculate(int s, int arr2[]) : inputs(s, arr2)
    {
        cout << "Constructor called" << endl;
    }
    int result()
    {
        int result = 0;
        result = sqrt(this->variance());
        return result;
    }
};
int main()
{
    int size = 10;
    int arr[size] = {10, 20, 53, 32, 46, 59, 61, 78, 80, 99, 150};
    calculate c1(size, arr);
    cout << "The answer is " << c1.result() << endl;
    return 0;
}