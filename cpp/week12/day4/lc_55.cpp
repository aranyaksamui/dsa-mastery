// 55. Jump Game

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
    bool canJump(vector<int>& nums)
    {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxReach == nums.size() - 1) return true;
            else if (i > maxReach) return false;
            
            maxReach = max(maxReach,  i + nums[i]);
        }

        return true;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {2, 3, 1, 1, 4};
        vector<int> nums = {3, 2, 1, 0, 4};

        cout << canJump(nums) << endl;

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