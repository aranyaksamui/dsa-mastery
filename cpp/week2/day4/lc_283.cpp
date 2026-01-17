// 283. Move Zeroes

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
    void moveZeroes(vector<int>& nums)
    {
        if (nums.size() <= 1) return;

        int slow = 0;
        while (slow < nums.size() && nums[slow] != 0) slow++;

        int fast = slow;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0 && fast != slow)
            {
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                if (slow < nums.size())
                    slow++;
                else break;
            }
        }
    }

    void solve()
    {
        // My test case code
        // vector<int> nums = {0, 1, 0, 3, 12};
        // vector<int> nums = {2, 5, 0, 1, 0, 3, 12, 0};
        // vector<int> nums = {0, 0};
        vector<int> nums = {2, 1};
        moveZeroes(nums);

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