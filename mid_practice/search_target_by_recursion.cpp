#include <iostream>
using namespace std;
void find_target(int arr[],int target,int start,int end){
    int middle = (start + end)/2;
    if(arr[middle]==target){
        cout<<"oye mil gaya samaan";
        cout<<middle;
    }
    else if (arr[middle]>target)
    {
        find_target(arr,target,start,middle-1);
    }
     else if (arr[middle]>target)
    {
        find_target(arr,target,middle+1,end);
    }
    
}
int main() {
    int arr[]={1,2,3,4,5,6};
    find_target(arr,3,0,5);

    return 0;
}