#include<iostream>
using namespace std;

class students {
    string Name;
    string Roll_No;
    string Section;

public:
    students() {}

    students(string name, string roll, string section) {
        Name = name;
        Roll_No = roll;
        Section = section;
    }

    void about_yourself() {
        cout << "My name is " << Name << endl;
        cout << "My Roll number is " << Roll_No << endl;
        cout << "I am in " <<  Section << endl;
        cout << "Thank You!!" << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of users you want to register: ";
    cin >> n;

    students arr[n];
    string name, roll, section;

    for (int i = 0; i < n; i++) {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll number: ";
        getline(cin, roll);

        cout << "Enter Section: ";
        getline(cin, section);

        arr[i] = students(name, roll, section);
    }

    for (int i = 0; i < n; i++) {
        arr[i].about_yourself();
    }

    return 0;
}
