// 704. Binary Search

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
    int searchHelper(vector<int>& n, int t, int low, int high)
    {
        int mid = low + (high - low) / 2;
        if (t == n[mid]) return mid;
        else if (t < n[mid] && low < high) return searchHelper(n, t, low, mid - 1);
        else if (t > n[mid] && low < high) return searchHelper(n, t, mid + 1, high);
        else return -1;
    }

    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        return searchHelper(nums, target, low, high);
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {-1, 0, 3, 5, 9, 12};
        // int target = 9;
        // cout << search(nums, target) << endl;

        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 2;
        cout << search(nums, target) << endl;

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