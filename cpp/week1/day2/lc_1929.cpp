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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
        // Your code will go here
        vector<int> v = {1, 3, 2, 1};
        getConcatenation(v);

        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;

        std::cout << "System ready." << std::endl;
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}