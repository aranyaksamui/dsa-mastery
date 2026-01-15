// 977. Squares of a Sorted Array

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
    vector<int> sortedSquares(vector<int>& nums)
    {
        for (int& x : nums) x = (x * x);
        sort(nums.begin(), nums.end());
        return nums;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {-4, -1, 0, 3, 10};
        for (int x : sortedSquares(nums)) cout << x << " ";

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