#include <iostream>
using namespace std;
int main()
{
    int size;
    int flag = 0;
    int index = 0;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    int count = 0;
    int target[size];
    for (int i = 0; i < size; i++)
    {
        if (flag == 1)
        {
            break;
        }
        index = 0;
        int temp = arr[i];
        target[index] = i;
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if ((temp + arr[j]) < sum)
            {
                index++;
                temp = temp + arr[j];
                target[index] = j;
                count++;
                cout << "Running " << endl;
                cout << temp << endl;
                
            }
            else if ((arr[j] + temp) == sum)
            {
                index++;
                target[index] = j;
                count++;
                cout << "Running 1" << endl;
                cout << temp << endl;
                flag = 1;
            }
            else if ((temp + arr[j]) > sum)
            {
                cout << "Running 3" << endl;
                cout << temp << endl;
                break;
            }
        }
    }
    cout << count << endl;
    cout << "[";
    for (int i = 0; i < count; i++)
    {
        cout << target[i] << " ";
    }
    cout << "]";

    return 0;
}