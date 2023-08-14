#include<iostream>
#include<string>
using namespace std;
class employee{
 string name;
 int age;
 
 public:
 static int count;
 void setthings(){
    cin.ignore();
    cout<<"Enter Name: ";
    getline(cin,name);
        cout<<"Enter age: ";
    cin>>age;
    count++;
 }
 void getname(){
cout<<"My name is "<<name<<endl;
 }
  void getcount(){
cout<<"total count is "<<count<<endl;
 }

};
int employee :: count;
int main(){
employee arr[3];



for (int i = 0; i < 3; i++)
{
    
    arr[i].setthings();
}
for (int i = 0; i < 3; i++)
{
    arr[i].getname();
}



return 0; }