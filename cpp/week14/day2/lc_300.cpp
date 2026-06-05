// 300. Longest Increasing Subsequence

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
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            int maxLength = 0;
            for (int j = 0; j < i; j++)
            {
                if (dp[j] >= maxLength && nums[i] > nums[j]) maxLength = dp[j];
                if (nums[i] > nums[j]) dp[i] = 1 + maxLength;
            }
        }

        int maxLen = 0;
        for (int x : dp) maxLen = max(maxLen, x);

        return maxLen;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        // vector<int> nums = {4, 10, 4, 3, 8, 9};
        vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};  
        
        lengthOfLIS(nums);
        
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