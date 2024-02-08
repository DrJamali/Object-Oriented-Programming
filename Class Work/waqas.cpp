#include <iostream>
using namespace std;

class opp{
    int arr[1];
    public:
    void set_data(int size){
        arr[size];
        for(int i=0; i<size; i++){
            cin>>arr[i];
        }
        get_data(size);
    }
    void get_data(int size){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    opp aq;
    aq.set_data(4);
    return 0;
}