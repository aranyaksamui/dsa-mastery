// 1008. Construct Binary Search Tree from Preorder Traversal

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

        cout << root->val << endl;

        traverseTree(root->left);
        traverseTree(root->right);
    }

    TreeNode* createNode(int val)
    {
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }

    TreeNode* insertIntoBST(vector<int>& arr, int& index, int bound)
    {
        if (index >= arr.size() || arr[index] > bound) return nullptr;

        TreeNode* root = createNode(arr[index]);

        index++;

        root->left = insertIntoBST(arr, index, root->val);
        root->right = insertIntoBST(arr, index, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int index = 0;
        TreeNode* root = insertIntoBST(preorder, index, INT16_MAX);
        
        return root;
    }

    void solve()
    {
        // My test case code
        vector<int> preorder = {8, 5, 1, 7, 10, 12};
        TreeNode* root = bstFromPreorder(preorder);

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