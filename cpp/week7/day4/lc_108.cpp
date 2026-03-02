// 108. Convert Sorted Array to Binary Search Tree

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

    TreeNode* insertIntoBST(TreeNode* root, vector<int>& nums, int low, int high)
    {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;
        
        root = createNode(nums[mid]);
        
        root->left = insertIntoBST(root->left, nums, low, mid - 1);
        root->right = insertIntoBST(root->right, nums, mid + 1, high);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        TreeNode* root = insertIntoBST(nullptr, nums, low, high);

        return root;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {-10, -3, 0, 5, 9};
        TreeNode* root = sortedArrayToBST(nums);

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