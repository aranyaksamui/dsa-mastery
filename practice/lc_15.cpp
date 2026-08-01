/*
    LeetCode: 15. 3Sum
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

// This function speeds up input/output operations
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Solution Class (Like LeetCode)
class Solution
{
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            int firstNum = nums[i];
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {   
                int threeSum = firstNum + nums[start] + nums[end];

                if (threeSum < 0) start++;
                if (threeSum > 0) end--;
                if (threeSum == 0)
                {
                    result.push_back({firstNum, nums[start], nums[end]});
                    start++;
                    while (nums[start] == nums[start - 1] && start < end)
                        start++;
                }

            }
        }

        return result;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {-1, 0, 1, 2, -1, 4};
        // vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};

        threeSum(nums);
        
        cout << endl << "System ready." << endl;
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}