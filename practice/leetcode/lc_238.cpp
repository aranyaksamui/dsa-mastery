/*
    LeetCode: 238. Product of Array Except Self
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
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int l = 0, r = n - 1; l < n && r >= 0; l++, r--)
        {
            if (!(l > 0 && r < n - 1))
            {
                prefix[l] = prefix[l] * nums[l];
                suffix[r] = suffix[r] * nums[r];
                continue;
            }

            prefix[l] = prefix[l - 1] * nums[l];
            suffix[r] = suffix[r + 1] * nums[r];
        }

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            int idx = i - 1;
            int revIdx = i + 1;

            if (idx < 0)
                result.push_back(suffix[revIdx]);
            else if (revIdx > n - 1)
                result.push_back(prefix[idx]);
            else
                result.push_back(prefix[idx] * suffix[revIdx]);
        }

        return result;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 2, 3, 4};
        // vector<int> nums = {-1, 1, 0, -3, 3};

        productExceptSelf(nums);
        
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