// 104. Maximum Depth of Binary Tree

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
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int level = 0;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (nodes.size() > 0)
        {
            int size = nodes.size();
            while (size > 0)
            {
                if (nodes.front()->left != nullptr) nodes.push(nodes.front()->left);
                if (nodes.front()->right != nullptr) nodes.push(nodes.front()->right);
                nodes.pop();
                size--;
            }
            level++;
        }

        return level;
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(15);
        TreeNode* leaf2 = new TreeNode(7);

        TreeNode* nl21 = new TreeNode(9, nullptr, nullptr);
        TreeNode* nl22 = new TreeNode(20, leaf1, leaf2);

        TreeNode* root = new TreeNode(3, nl21, nl22);

        cout << maxDepth(root) << endl;

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