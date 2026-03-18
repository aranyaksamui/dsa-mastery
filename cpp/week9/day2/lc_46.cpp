// 46. Permutations

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
private:
    vector<vector<int>> permutation;
public:
    void permuteHelper(vector<int>& nums, vector<int>& currentState, unordered_map<int, bool> selected)
    {
        if (currentState.size() == nums.size())
        {
            permutation.push_back(currentState);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (selected[nums[i]] == true) continue;

            currentState.push_back(nums[i]);
            selected[nums[i]] = true;

            permuteHelper(nums, currentState, selected);

            currentState.pop_back();
            selected[nums[i]] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> currentState;
        
        unordered_map<int, bool> selected;
        for (int x : nums) selected[x] = false;

        permuteHelper(nums, currentState, selected);

        return permutation;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 2, 3};
        for (vector<int>& v : permute(nums))
        {
            for (int x : v) cout << x << ", ";
            cout << endl;
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