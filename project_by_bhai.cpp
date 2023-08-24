#include <iostream>
using namespace std;
class Person
{
protected:
    int age;
    string Name;
    string arr_of_subjects[10000];
    int size;

public:
    virtual void setage(int a) = 0;
    virtual void setname(string s) = 0;
};
class Students : protected Person
{
public:
    void setsubjects()
    {
        cout << "Enter the Number of subjects: ";
        cin >> size;
        arr_of_subjects[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin.ignore();
            cout << "Enter the Name of subject: ";
            getline(cin, arr_of_subjects[i]);
        }
        arr_of_subjects[i] = "Flag";
    }
    void setage(int a)
    {
        age = a;
    }
    void setname(string s)
    {

        Name = s;
    }
    int getage()
    {
        return age;
    }
    string get_name()
    {
        return Name;
    }
    string getsubjects(int i)
    {
        return arr_of_subjects[i];
    }
};
class Teacher : protected Person
{
    int employee_id;

public:
    void setid(int a)
    {
        employee_id = a;
    }
    void setsubjects()
    {
        cout << "Enter the Number of subjects";
        cin >> size;
        arr_of_subjects[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin.ignore();
            cout << "Enter the Name off subject: ";
            getline(cin, arr_of_subjects[i]);
        }
        arr_of_subjects[i] = "Flag";
    }
    void setage(int a)
    {
        age = a;
    }
    void setname(string s)
    {
        Name = s;
    }
    int getage()
    {
        return age;
    }
    string get_name()
    {
        return Name;
    }
    string getsubjects(int i)
    {
        return arr_of_subjects[i];
    }
    int getsize()
    {
        return size;
    }
};

int main()
{
    int type;
    string tempname;
    int age;
    int id;
    int tsize;
    int stsize;

    Teacher *temptptr;
    Students *tempsptr;
    Teacher *temptptr2;
    Students *tempsptr2;
    Teacher *temptptr3;
    Students *tempsptr3;

    cout << "Enter the number of Teachers you want to enter: ";

    cin >> tsize;
    Teacher *tptr = new Teacher[tsize];
    temptptr = tptr;
    temptptr2 = temptptr;
    for (int i = 0; i < tsize; i++)
    {
        cout << "Enter Your ID: ";
        cin >> id;
        tptr->setid(id);
        cin.ignore();
        cout << "Enter Your Name: ";
        getline(cin, tempname);
        tptr->setname(tempname);
        cout << "Enter age: ";
        cin >> age;
        tptr->setage(age);
        tptr->setsubjects();
        tptr++;
    }

    cout << "Enter the number of Students you want to enter: ";
    cin >> stsize;
    Students *sptr = new Students[stsize];
    tempsptr = sptr;
    tempsptr2 = tempsptr;
    for (int i = 0; i < stsize; i++)
    {
        cin.ignore();
        cout << "Enter Your Name: ";
        getline(cin, tempname);
        sptr->setname(tempname);
        cout << "Enter age: ";
        cin >> age;
        sptr->setage(age);
        sptr->setsubjects();
        sptr++;
    }

    string subj[10000];
    int k;
    int n = 0;
    for (int i = 0; i < stsize; i++)
    {
        int k = 0;
        while (tempsptr->getsubjects(k) != "Flag")
        {
            subj[n] = tempsptr->getsubjects(k);
            n++;
            k++;
        }
        tempsptr++;
    }
    for (int i = 0; i < stsize; i++)
    {
        int k = 0;
        while (temptptr->getsubjects(k) != "Flag")
        {
            subj[n] = temptptr->getsubjects(k);
            n++;
            k++;
        }
        temptptr++;
    }
    subj[n] = "Flag2";

    string avoidRepetition[n];
    int m = 0, flag = 0;
    while (subj[m] != "Flag2")
    {
        flag = 0;
        avoidRepetition[m] = subj[m];
        for (int i = 0; i < m; i++)
        {
            if (subj[m] == avoidRepetition[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            continue;
        }
        tempsptr3 = tempsptr2;
        temptptr3 = temptptr2;
        cout << subj[m];
        cout << "Students: " << endl;
        ;
        for (int i = 0; i < stsize; i++) // Reset the loop variable i
        {
            int j = 0;
            while (tempsptr3->getsubjects(j) != "Flag")
            {
                if (tempsptr3->getsubjects(j) == subj[m])
                {
                    cout << tempsptr3->get_name() << endl;
                    break;
                }
                j++;
            }
            tempsptr3++;
        }
        cout << "Teachers: " << endl;

        for (int i = 0; i < stsize; i++) // Reset the loop variable i
        {
            int j = 0;
            while (temptptr3->getsubjects(j) != "Flag")
            {
                if (temptptr3->getsubjects(j) == subj[m])
                {
                    cout << temptptr3->get_name() << endl;
                    break;
                }
                j++;
            }
            temptptr3++;
        }
        m++;
    }

    return 0;
}