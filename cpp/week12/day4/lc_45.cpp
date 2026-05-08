// 45. Jump Game II

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
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int jumps = 0, maxReach = 0, current = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxReach = max(maxReach, i + nums[i]);
            
            if (i == current)
            {
                jumps++;
                current = maxReach;
            }
        }

        return jumps;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {2, 3, 1, 1, 4};
        vector<int> nums = {2, 3, 0, 1, 4};
        // vector<int> nums = {1, 2, 1, 1, 1};
        // vector<int> nums = {1, 1, 1, 1};
        // vector<int> nums = {2, 1};

        cout << jump(nums) << endl;

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