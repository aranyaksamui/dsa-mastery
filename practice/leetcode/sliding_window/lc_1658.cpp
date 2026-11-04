/*
    LeetCode: 1658. Minimum Operations to Reduce X to Zero
*/

// #include <bits/stdc++.h>

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
    int minOperations(vector<int>& nums, int x)
    {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // Must remain sum for the keeping middle part of the subarray while x becomes 0
        int remain = totalSum - x;

        // Edge case: if x == totalSum remove all the elements then return nums size
        if (remain == 0) return nums.size();
        
        // Edge case: If x > totalSum it is impossible return -1
        if (remain < 0) return -1;

        int maxLen = -1;
        int currSum = 0;
        int l = 0;

        // Sliding window to find the longest sub array that sums upto remaining elements in nums
        for (int r = 0; r < nums.size(); r++)
        {
            currSum += nums[r];

            // Shrink window from left if current sum becomes greater than remaining sum
            while (currSum > remain && l <= r)
            {
                currSum -= nums[l];
                l++;
            }

            // If we hit the remaining sum then record the maximum length found
            if (currSum == remain) maxLen = max(maxLen, r - l + 1);
        }

        // If maxLen got updated inside the main loop the remaining elements are our min operations
        return (maxLen == -1) ? -1 : nums.size() - maxLen;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {1, 1, 4, 2, 3};
        // int x = 5;

        // vector<int> nums = {5, 6, 7, 8, 9};
        // int x = 4;

        vector<int> nums = {3, 2, 20, 1, 1, 3};
        int x = 10;

        cout << minOperations(nums, x) << endl;
        
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