// 538. Convert BST to Greater Tree

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
private:
    int runningSum = 0;

public:
    TreeNode* convertBST(TreeNode* root)
    {
        if (root == nullptr) return nullptr;

        convertBST(root->right);

        runningSum += root->val;
        root->val = runningSum;

        convertBST(root->left);

        return root;
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(0);
        TreeNode* leaf2 = new TreeNode(3);
        TreeNode* leaf3 = new TreeNode(5);
        TreeNode* leaf4 = new TreeNode(8);

        TreeNode* nl31 = new TreeNode(2, nullptr, leaf2);
        TreeNode* nl32 = new TreeNode(7, nullptr, leaf4);

        TreeNode* nl21 = new TreeNode(1, leaf1, nl31);
        TreeNode* nl22 = new TreeNode(6, leaf3, nl32);

        TreeNode* root = new TreeNode(4, nl21, nl22);

        convertBST(root);

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