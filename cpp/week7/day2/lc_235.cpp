// 235. Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode* ancestor;

        if (root == nullptr) return nullptr;

        if (root->left == nullptr && root->right == nullptr) return root;

        if (root->left != nullptr || root->right != nullptr)
        {
            if (p->val <= root->val && q->val >= root->val || p->val >= root->val && q->val <= root->val)
                ancestor = root;
            else if (p->val < root->val && q->val < root->val)
                return lowestCommonAncestor(root->left, p, q);
            else if (p->val > root->val && q->val > root->val)
                return lowestCommonAncestor(root->right, p, q);
            else return nullptr;
        }
        else return nullptr;

        return ancestor;
    }

    void solve()
    {
        // My test case code
        TreeNode *leaf1 = new TreeNode(0);
        TreeNode *leaf2 = new TreeNode(3);
        TreeNode *leaf3 = new TreeNode(5);
        TreeNode *leaf4 = new TreeNode(7);
        TreeNode *leaf5 = new TreeNode(9);

        TreeNode *nl31 = new TreeNode(4, leaf2, leaf3);

        TreeNode *nl21 = new TreeNode(2, leaf1, nl31);
        TreeNode *nl22 = new TreeNode(8, leaf4, leaf5);

        TreeNode *root = new TreeNode(6, nl21, nl22);

        cout << lowestCommonAncestor(root, nl21, nl22)->val << endl;

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