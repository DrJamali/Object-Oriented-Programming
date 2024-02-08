#include <iostream>
using namespace std;
int avg(int *arr)
{
    
    for (int i = 1; i < 5; i++)
    {
        arr[0] = arr[0] + arr[i];
    }
    cout << "The average is " << arr[0]/(sizeof(arr)/sizeof(int)) << endl;

}
int main()
{
int arr[5] = {1, 2, 3, 4, 5};
avg(arr);
    
    return 0;
}