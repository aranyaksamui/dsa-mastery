// 198. House Robber (not yet complete)

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
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1) return nums[0];

        int p1 = 0;
        int p2 = 1;
        
        int sum1 = 0;
        int sum2 = 0;
        
        if (n % 2 == 0) 
        {
            for (; p1 < n - 1 && p2 < n; p1 += 2, p2 += 2)
            {
                sum1 += nums[p1];
                sum2 += nums[p2];
            }
        }
        else
        {
            for (; p1 < n || p2 < n - 1; p1 += 2, p2 += 2)
            {
                sum1 += nums[p1];
                if (p2 < n - 1) sum2 += nums[p2];
            }
        }

        return max(sum1, sum2);
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 2, 3, 1};

        cout << rob(nums) << endl;
        
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