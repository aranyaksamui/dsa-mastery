// The Challenge: LeetCode 169

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
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int i = 0, newNum, numStart = 0;
        pair<int, int> numCount = {0, 0};
        newNum = nums[0];
        numCount.first = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != newNum)
            {
                if (i - numStart >= numCount.second)
                {
                    numCount.first = newNum;
                    numCount.second = i == nums.size() - 1 ? (i + 1) - numStart : i - numStart;
                }
                newNum = nums[i];
                numStart = i;
            }
            else if (i == nums.size() - 1)
            {
                if ((i + 1) - numStart >= numCount.second)
                {
                    numCount.first = newNum;
                    numCount.second = (i + 1) - numStart;
                }
            }
        }
        
        return numCount.first;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {2, 2, 2, 1, 1, 1, 1, 3, 3, 3};
        cout << "Majority Element: " << majorityElement(nums) << endl;

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
