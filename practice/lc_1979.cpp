/*
    LeetCode: 1979. Find Greatest Common Divisor of Array
*/

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
    int calculateGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    int findGCD(vector<int>& nums)
    {
        int n = nums.size();
        int smallNum = __INT32_MAX__;
        int bigNum = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < smallNum) smallNum = nums[i];
            if (nums[i] > bigNum) bigNum = nums[i];
        }
        
        return calculateGCD(bigNum, smallNum);
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {7, 5, 6, 8, 3};

        cout << findGCD(nums) << endl;

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