// 98. Validate Binary Search Tree

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
#include <limits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    bool checkValidBST(TreeNode* root, long long min, long long max)
    {
        if (root == nullptr) return true;

        if (root->val >= max) return false;
        if (root->val <= min) return false;

        bool isValidLeftTree = checkValidBST(root->left, min, root->val);
        bool isValidRightTree = checkValidBST(root->right, root->val, max);

        return isValidLeftTree && isValidRightTree;
    }

    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) return true;

        long long max = numeric_limits<long long>::max();
        long long min = numeric_limits<long long>::min();

        return checkValidBST(root, min, max);
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(3);
        TreeNode* leaf2 = new TreeNode(6);

        TreeNode* nl21 = new TreeNode(1, nullptr, nullptr);
        TreeNode* nl22 = new TreeNode(4, leaf1, leaf2);

        TreeNode* root = new TreeNode(5, nl21, nl22);

        cout << isValidBST(root) << endl;

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