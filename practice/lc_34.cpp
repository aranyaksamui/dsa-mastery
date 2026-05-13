// 34. Find First and Last Position of Element in Sorted Array

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
private:
    vector<int> indices;
public:
    void searchRangeHelper(vector<int>& nums, int start, int end, int target)
    {
        int mid = start + (end - start) / 2;
        cout << mid << endl;

        
        if (start >= end)
        {
            if (nums[mid] != target) return;

            indices.push_back(mid);
            return;
        }
        
        searchRangeHelper(nums, start, mid - 1, target);
        searchRangeHelper(nums, mid + 1, end, target);
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        searchRangeHelper(nums, start, end, target);

        return indices;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        int target = 8;

        searchRange(nums, target);
        for (int x : indices) cout << x << endl;

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