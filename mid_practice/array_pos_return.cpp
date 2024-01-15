#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0;
        int stop = 0;
        int indices=0;
        if (target > nums[(nums.size() / 2) - 1])
        {
            // i = nums[(nums.size() / 2) - 1];
            indices=(nums.size() / 2) - 1;
            stop = nums.size();
        }
        else
        {
            i=nums[0];
            stop = (nums.size() / 2);
        }
        
        for (indices<stop;indices++;)
        {
            if (nums[indices] == target)
            {
                return indices;
            }
            else if (nums[indices] > target)
            {
                return indices-1;
            }
        }
        return indices;
    }
};
int main()
{
    Solution S1;
    vector<int> arr= {1,3,5,6};
    cout<<S1.searchInsert(arr,7)<<endl;
    return 0;
}