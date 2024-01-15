#include <iostream>
using namespace std;
int Sum_Of_Even_Elements(int *arr, int size)
{
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < size; i++)
    {
        if (*ptr % 2 == 0)
        {
            sum = sum + *ptr;
        }
        ptr++;
    }
    return sum;
}

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(arr) / sizeof(arr[0]);
int solution = Sum_Of_Even_Elements(arr, size);
cout<"Hello world";
