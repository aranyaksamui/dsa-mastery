// 496. Next Greater Element I

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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        stack<int> numStack;
        unordered_map<int, int> numMap;

        for (int currentNum : nums2)
        {
            while (!numStack.empty() && currentNum > numStack.top())
            {
                numMap[numStack.top()] = currentNum;
                numStack.pop();
            }
            numStack.push(currentNum);
        }

        for (int x : nums1)
        {
            if (numMap.count(x)) res.push_back(numMap.at(x));
            else res.push_back(-1);
        }

        return res;
    }

    void solve()
    {
        // My test case code
        vector<int> nums1 = {4, 1, 2};
        vector<int> nums2 = {1, 3, 4, 2};

        for (int x : nextGreaterElement(nums1, nums2))
        {
            cout << x << endl;
        }


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