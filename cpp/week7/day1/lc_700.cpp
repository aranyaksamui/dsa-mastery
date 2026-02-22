// 700. Search in a Binary Search Tree

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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) return nullptr;

        if (val < root->val) return searchBST(root->left, val);
        else if (val > root->val) return searchBST(root->right, val);
        else if (val == root->val) return root;
        else return nullptr;
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(1);
        TreeNode* leaf2 = new TreeNode(3);

        TreeNode* nl21 = new TreeNode(2, leaf1, leaf2);
        TreeNode* nl22 = new TreeNode(7, nullptr, nullptr);

        TreeNode* root = new TreeNode(4, nl21, nl22);

        int val = 6;
        cout << searchBST(root, val)->val << endl;

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