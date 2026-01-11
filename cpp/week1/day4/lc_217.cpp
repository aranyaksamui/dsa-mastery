// 217. Contains Duplicate

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
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i+1])
                return true;
        }
    
        return false;
    }

    void solve()
    {
        // My test case code
        vector<int> nums1= {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        vector<int> nums2 = {1, 2, 3, 4};
        cout << containsDuplicate(nums1) << endl;
        cout << containsDuplicate(nums2) << endl;

        cout << "System ready." << endl;
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}