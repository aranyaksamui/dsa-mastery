/*
    WEEK 1: C++ STL & Big O
    DAY 3: Loops, References and Iterators

    LeetCode: 1480. Running Sum of 1d Array
*/ 


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
    vector<int> runningSum(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }

    void solve()
    {
        vector<int> arr = {1, 2, 3, 4};

        // My test case code
        for (int x : runningSum(arr))
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