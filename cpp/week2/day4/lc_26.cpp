// 26. Remove Duplicates from Sorted Array

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
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 1) return 1;

        int slow = 0;
        int fast = 1;
        for (; fast < nums.size(); fast++)
        {
            if (nums[slow] != nums[fast])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        vector<int> nums = {1, 1, 2};
        cout << endl << "No. of unique elements (k): " << removeDuplicates(nums) << endl;
        
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