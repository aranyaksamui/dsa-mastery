// 643. Maximum Average Subarray I

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

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
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double currentSum = 0;
        double maxAvg = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                currentSum += nums[i];
                maxAvg = currentSum / k;
            }
            else
            {
                currentSum = currentSum - nums[i-k] + nums[i];
                if ((currentSum / k) > maxAvg) maxAvg = currentSum / k;
            }
        }

        return maxAvg;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {1, 12, -5, -6, 50, 3};
        // vector<int> nums = {1, 12, -5, -6};
        vector<int> nums = {4};
        int k = 1;
        // findMaxAverage(nums, k);
        cout << findMaxAverage(nums, k) << endl;

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