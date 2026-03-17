// 78. Subsets

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

// Definition for singly-linked list for Linked List problems.
// struct ListNode
// {
//     int val;
//     ListNode *next;

//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// Definition for a binary tree node.
// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
    vector<vector<int>> subsetsList;

public:
    void subsetsHelper(vector<int>& nums, vector<int>& currentSubset, int i)
    {
        if (i >= nums.size())
        {
            subsetsList.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[i]);
        subsetsHelper(nums, currentSubset, i + 1);

        currentSubset.pop_back();
        subsetsHelper(nums, currentSubset, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        if (nums.size() <= 0) return {{}};

        vector<int> currentSubset;
        int i = 0;

        subsetsHelper(nums, currentSubset, i);
        return subsetsList;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 2, 3};
        for (vector<int>& subset : subsets(nums))
        {
            for (int x : subset)
            {
                cout << x << ", ";
            }
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