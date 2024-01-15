#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     int way=0;
    //     int step = 0;
    //     int pre_Step;
    //     for (int i = 0; i < triangle.size(); i++)
    //     {
    //         if(i==0){
    //             way=triangle[i][i];
    //             continue;
    //         }
    //         int min = INT32_MAX;
    //         pre_Step=step;
    //         for (int j = pre_Step; ((j <=pre_Step+1) && (j<=i)); j++)
    //         {
    //             if (triangle[i][j] < min)
    //             {
    //                 min = triangle[i][j];
    //                 step=j;
                   
    //             }
    //             cout<<i<<" "<<j<<endl;
    //             cout<<step<<endl;
    //         }
    //         way = way + min;
    //     }
    //     return way;
    // }

int minimumTotal(vector<vector<int>>& triangle) {
    // Start from the second row and update the minimum path sum for each element
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            // Update the current element with the sum of itself and the minimum of its two adjacent elements from the above row
            if (j == 0) {
                triangle[i][j] += triangle[i - 1][j];
            } else if (j == triangle[i].size() - 1) {
                triangle[i][j] += triangle[i - 1][j - 1];
            } else {
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
    }

    // Find the minimum path sum at the bottom row
    int minSum = INT32_MAX;
    for (int num : triangle.back()) {
        minSum = min(minSum, num);
    }

    return minSum;
    
    }};
int main()
{
    Solution S1;
    So
    vector<vector<int>> triangle = {{-1},{2,3},{1,-1,-3}};
    int way = S1.minimumTotal(triangle);
    // 
    cout << "way" << way;
    // cout<<way<<endl;
}