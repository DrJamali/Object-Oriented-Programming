#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max=INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]>max)
            {
                max=nums[i];
            }
        }
        if (nums[0]=max)
        {
            return 0;
        }
        
        for ( i = 0; i < count; i++)
        {
            /* code */
        }
        
        
        
    }
};
int main() {
    return 0;
}