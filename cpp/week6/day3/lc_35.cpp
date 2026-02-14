// 35. Search Insert Position

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
    int seInsHelper(vector<int>& nums, int target, int low, int high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid] && low < high) return seInsHelper(nums, target, low, mid - 1);
        else if (target > nums[mid] && low < high) return seInsHelper(nums, target, mid + 1, high);
        else return target > nums[mid] ? mid + 1 : mid;
    }

    int searchInsert(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        return seInsHelper(nums, target, low, high);
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 3, 5, 6};
        // int target = 5;
        // cout << searchInsert(nums, target) << endl;

        int target = 7;
        cout << searchInsert(nums, target) << endl;

        // int target = 0;
        // cout << searchInsert(nums, target) << endl;



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