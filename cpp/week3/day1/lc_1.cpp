// 1. Two Sum

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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> indices(2, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            if (!mp.count(nums[i])) mp[nums[i]] = i;
            else if (mp.count(target - nums[i]))
            {
                indices[0] = mp.at(target - nums[i]);
                indices[1] = i;
                return indices;
            }

            if (mp.count(nums[i]) && mp.count(target - nums[i]) && mp.at(target - nums[i]) != mp.at(nums[i]))
            {
                indices[0] = mp.at(target - nums[i]);
                indices[1] = mp.at(nums[i]);
                return indices;
            }
        }

        return indices;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {2, 7, 11, 15};
        vector<int> nums = {2, 4, 11, 3};
        // vector<int> nums = {3, 2, 4};
        // vector<int> nums = {3, 3};
        int target = 6;
        for (int x : twoSum(nums, target)) cout << x << " ";
        
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