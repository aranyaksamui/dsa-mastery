/*
    LeetCode: 3867. Sum of GCD of Formed Pairs
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
    int gcd (int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    long long gcdSum(vector<int>& nums)
    {
        vector<int> prefixGcd;
        
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd.push_back(gcd(mx, nums[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int start = 0;
        int end = nums.size() - 1;
        long long gcdSumResult = 0;
        while(start < end)
        {
            gcdSumResult += gcd(prefixGcd[start], prefixGcd[end]);

            start++;
            end--;
        }

        return gcdSumResult;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {3, 6, 2, 8};
        // vector<int> nums = {2, 6, 4};
        
        cout << gcdSum(nums) << endl;
        
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