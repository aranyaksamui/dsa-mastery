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
    // My actual function
    vector<int> getConcatenation(vector<int>& nums)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++) nums.push_back(nums[i]);
        return nums;
    }

    void solve()
    {
        // My test case code
        vector<int> v = {1, 3, 2, 1};
        getConcatenation(v);

        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;

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