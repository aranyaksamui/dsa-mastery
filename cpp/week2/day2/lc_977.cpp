// WORK IN PROGRESS
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
        int start = 0;
        int end = nums.size() - 1;

        vector<int> result;
        while (start <= end)
        {
            int a, b;
            a = nums[start] * nums[start];
            b = nums[end] * nums[end];

            // Work in progress
            
            start++;
            end--;
        }
        return result;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {-4, -1, 0, 3, 10};
        for (int x : sortedSquares(nums)) cout << x << " ";

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