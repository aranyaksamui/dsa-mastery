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
    // My actual function
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }

    void solve()
    {
        // My test case code
        vector<int> nums1 = {5, 0, 1, 2, 3, 4};
        vector<int> nums2 = {0, 2, 1, 5, 3, 4};

        for (int x : buildArray(nums2))
        {
            cout << x << " ";
        }
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}