/*
    485. Max Consecutive Ones
*/

#include <bits/stdc++.h>

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
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int s = 0;
        int e = 0;
        int maxLength = 0;

        for (; s < nums.size() && e < nums.size(); e++)
        {
            // If we encounter a 0 then set start (s) to End + 1 (e + 1) and continue to next iteration (e = e + 1)
            if (nums[e] == 0)
            {
                s = e + 1;
                continue;
            } 

            // Compare the consecutive length of previous vs current + 1 length
            maxLength = max(maxLength, (e - s) + 1);
        }

        return maxLength;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 1, 0, 1, 1, 1};
        
        // vector<int> nums = {1, 0, 1, 1, 0, 1};

        cout << findMaxConsecutiveOnes(nums) << endl;
        
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