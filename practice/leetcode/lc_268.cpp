/*
    LeetCode: 268. Missing Number
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
    int missingNumber(vector<int>& nums)
    {
        unordered_map<int, int> numsPresent;
        int n = nums.size();

        for (int i = 0; i < n; i++) numsPresent[nums[i]] = 1;

        int missingNum = -1;
        for (int i = n; i >= 0; i--) if (!numsPresent.count(i)) missingNum = i;

        return missingNum;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

        cout << missingNumber(nums) << endl;
        
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