/*
    LeetCode: 1004. Max Consecutive Ones III
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
    int longestOnes(vector<int>& nums, int k)
    {
        if (k >= nums.size()) return nums.size();

        int zeros = 0;
        int maxLength = 0;
        int s = 0;
        int e = 0;

        // Loop through the array with end pointer start to end
        for (; e < nums.size(); e++)
        {
            // If we encounter a 0 then increase the 0 counter
            if (nums[e] == 0) zeros++;
            
            // If the 0 counter becomes > k then move the start pointer right until 0 counter becomes <= k
            while (zeros > k)
            {
                // If the start counter encounters a 0 meanwhile then decrease the 0 counter
                if (nums[s] == 0) zeros--;
                s++;
            }

            // Always calculate maxLength at every step of end pointer
            maxLength = max(maxLength, (e + 1) - s);
        }

        return maxLength;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
                         // 0  1  2  3  4  5  6  7  8  9 10 
        int k = 2;

        // vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
        //                 //  0  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
        // int k = 3;

        // vector<int> nums = {0, 0, 1, 1};
        // int k = 1;

        cout << longestOnes(nums, k) << endl;

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