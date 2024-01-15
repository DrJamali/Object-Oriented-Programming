// In this approch i have not used the in k in reverse array and i swap the elements with the swap function instead of making temp and other variables
#include <iostream>
using namespace std;
int *reverse_array(int *array, int size, int k)
{

    for (int i = 0; i < size / 2; i++)
    {
        
        swap(ptr[i], ptr[(size - 1) - i]);
    }
}
int *rotate_arr(int *array, int size, int k)
{
    int n = size - k;
    int *ptr = &array[n];
    reverse_array(array, size - k, 0);
    reverse_array(ptr, size - n, 0);
    reverse_array(array, size, 0);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int k = 2;
    // reverse_array(arr,size,k);
    rotate_arr(arr, size, k);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}