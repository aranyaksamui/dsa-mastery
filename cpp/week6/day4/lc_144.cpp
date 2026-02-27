// 144. Binary Tree Inorder Traversal

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
    void traversalHelper(TreeNode* root, vector<int>& elements)
    {
        if (root == nullptr) return;

        elements.push_back(root->val);

        traversalHelper(root->left, elements);
        traversalHelper(root->right, elements);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> elements;
        
        traversalHelper(root, elements);

        return elements;
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(4);
        TreeNode* leaf2 = new TreeNode(6);
        TreeNode* leaf3 = new TreeNode(7);
        TreeNode* leaf4 = new TreeNode(9);

        TreeNode* nl31 = new TreeNode(5, leaf2, leaf3);
        TreeNode* nl32 = new TreeNode(8, leaf2, nullptr);

        TreeNode* nl21 = new TreeNode(2, leaf1, nl31);
        TreeNode* nl22 = new TreeNode(3, nullptr, nl32);

        TreeNode* root = new TreeNode(1, nl21, nl22);

        vector<int> output = postorderTraversal(root);

        for (int x : output) cout << x << " ";

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