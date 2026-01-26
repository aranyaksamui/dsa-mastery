// 219. Contains Duplicate II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

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
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if (k >= nums.size()) k = nums.size() - 1;
        if (nums.size() <= k || k <= 0) return false;

        unordered_set<int> ns;

        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            if (j <= k)
            {
                ns.insert(nums[j]);
                if (j == k && ns.size() < k + 1) return true;
                j++;
            }
            else if (j > k)
            {
                ns.erase(nums[i]);
                i++;
                ns.insert(nums[j]);
                if (j - i == k && ns.size() < k + 1) return true;
                j++;
            }
        }
        return false;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {1, 2, 3, 1};
        // int k = 3;
        // cout << containsNearbyDuplicate(nums, k);

        // vector<int> nums = {1, 0, 1, 1};
        // int k = 1;
        // cout << containsNearbyDuplicate(nums, k);

        // vector<int> nums = {1, 2, 3, 1, 2, 3};
        // int k = 2;
        // cout << containsNearbyDuplicate(nums, k);

        // vector<int> nums = {1, 1, 1, 2, 3, 4};
        // int k = 3;
        // cout << containsNearbyDuplicate(nums, k);

        vector<int> nums = {99, 99};
        int k = 2;
        cout << containsNearbyDuplicate(nums, k);

        

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