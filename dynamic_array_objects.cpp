#include <iostream>
using namespace std;

class bakery
{
    int id;
    string name;

public:
    void setdata(int a, string s)
    {
        id = a;
        name = s;
    }
    void getdata()
    {
        cout << "Id of this item is: " << id << endl
             << "Name of the product is: " << name << endl;
    }
};

int main()
{
    int size = 3;
    bakery *ptr = new bakery[size];
    bakery *tempptr = ptr;
    int a;
    string s;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the id of your product: ";
        cin >> a;
        cout << "Enter the name of your product: ";
        cin.ignore();
       getline(cin, s);
        ptr->setdata(a, s);
        ptr++;
    }
    for (int i = 0; i < size; i++)
    {

        tempptr->getdata();
        tempptr++;
    }

    return 0;
}