/*
    LeetCode: 101. Symmetric Tree
*/

#include <bits/stdc++.h>

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
    bool checkSymmetry(TreeNode* leftRoot, TreeNode* rightRoot)
    {
        // Base case 1: If both the pointers at left most and right most leaf node is null
        if (leftRoot == nullptr && rightRoot == nullptr) return true;

        // If either of the left most or right most node is null pointer (but not the other) or the values inside them don't match
        if (leftRoot == nullptr || rightRoot == nullptr || leftRoot->val != rightRoot->val) return false;

        // First recursively check the left most and right most node of the current left and right root
        // Secondly recursively check the right of left root and left of right root
        // AND them and return the bool result
        return checkSymmetry(leftRoot->left, rightRoot->right) && checkSymmetry(leftRoot->right, rightRoot->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;

        return checkSymmetry(root->left, root->right);
    }

    void solve()
    {
        // My test case code
        
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