#include <iostream>
using namespace std;

// Function to print the elements of an array
void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// Function to initialize an array by taking user input
void Initialize_array(int arr[], int size)
{
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

// Function to sort an array in both ascending and descending order using the bubble sort algorithm
void sort(int arr[], int size)
{
    // Sorting in ascending order
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorting array in ascending manner is: ";
    print_arr(arr, size);
    cout << endl;

    // Sorting in descending order
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorting array in descending manner is: ";
    print_arr(arr, size);
    cout << endl;
}

// Function to find the sum of even elements in an array
int sum_even_elements(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }
    return sum;
}

// Function to reverse an array
void arr_reverse(int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
    cout<<"array reverse is"<<endl;
        print_arr(arr, size);
    cout << endl;
}

// Function to find the minimum element in an array and swap it with the first element
void find_min(int *arr, int size)
{
    int min = INT32_MAX;
    int index;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    swap(arr[0], arr[index]);
    cout << "The minimum element is now swapped with the first element";
    print_arr(arr, size);
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    Initialize_array(arr, size);

    int ch;
    cout << "Enter 1 to sort the array" << endl
         << "Enter 2 to find the sum of even elements" << endl
         << "Enter 3 to reverse the array" << endl
         << "Enter 4 to find the minimum element" << endl;
    cin >> ch;

    if (ch == 1)
    {
        sort(arr, size);
    }
    else if (ch == 2)
    {
        int result = sum_even_elements(arr, size);
        cout << "The sum of even elements is " << result << endl;
    }
    else if (ch == 3)
    {
        arr_reverse(arr, size);
    }
    else if (ch == 4)
    {
        find_min(arr, size);
    }

    return 0;
}
