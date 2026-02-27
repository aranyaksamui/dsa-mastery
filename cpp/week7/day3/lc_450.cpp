// 450. Delete Node in a BST

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
    void traverseTree(TreeNode* root)
    {
        if (root == nullptr) return;

        cout << root->val << " ";

        traverseTree(root->left);
        traverseTree(root->right);
    }

    TreeNode* minRightNode(TreeNode* root)
    {
        if (root->left == nullptr) return root;
        
        return minRightNode(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) return nullptr;

        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else if (key == root->val)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if ((root->left != nullptr && root->right == nullptr))
            {
                TreeNode* child = root->left;
                delete root;
                return child;
            }
            else if ((root->left == nullptr && root->right != nullptr))
            {
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            else
            {
                TreeNode* replacerNode = minRightNode(root->right);
                root->val = replacerNode->val;
                root->right = deleteNode(root->right, replacerNode->val);
            }
        }

        return root;
    }

    void solve()
    {
        // My test case code
        TreeNode *leaf1 = new TreeNode(2);
        TreeNode *leaf2 = new TreeNode(4);
        TreeNode *leaf3 = new TreeNode(7);

        TreeNode *nl21 = new TreeNode(3, leaf1, leaf2);
        TreeNode *nl22 = new TreeNode(6, nullptr, leaf3);

        TreeNode *root = new TreeNode(5, nl21, nl22);

        int key = 3;
        deleteNode(root, key);

        traverseTree(root);
        
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