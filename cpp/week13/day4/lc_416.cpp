// 416. Partition Equal Subset Sum

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
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();

        int sum = 0;
        for (int x : nums) sum += x;
        
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i < dp.size(); i++)
            dp[i][0] = true;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int c = 1; c < dp[i].size(); c++)
            {
                dp[i][c] = dp[i - 1][c];

                if (c >= nums[i - 1])
                    dp[i][c] = dp[i][c] || dp[i - 1][c - nums[i - 1]];
            }
        }

        return dp[n][target];
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 5, 11, 5};

        canPartition(nums);

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