// 230. Kth Smallest Element in a BST

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
    void getElements(TreeNode* root, vector<int>& elements)
    {
        if (root == nullptr) return;

        getElements(root->left, elements);

        elements.push_back(root->val);

        getElements(root->right, elements);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> elements;

        getElements(root, elements);

        return elements[k - 1];
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf2 = new TreeNode(1);

        TreeNode* nl31 = new TreeNode(2, leaf2, nullptr);
        TreeNode* leaf1 = new TreeNode(4);

        TreeNode* nl21 = new TreeNode(3, nl31, leaf1);
        TreeNode* nl22 = new TreeNode(6);

        TreeNode* root = new TreeNode(5, nl21, nl22);

        int k = 3;

        cout << kthSmallest(root, k) << endl;
        
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