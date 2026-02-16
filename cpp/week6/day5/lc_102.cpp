// 102. Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr) return {};

        queue<TreeNode*> nodes;
        vector<vector<int>> nodeVals;

        nodes.push(root);
        
        while (nodes.size() > 0)
        {
            int size = nodes.size();
            vector<int> levelVals;
            while (size > 0)
            {
                levelVals.push_back(nodes.front()->val);
                if (nodes.front()->left != nullptr) nodes.push(nodes.front()->left);
                if (nodes.front()->right != nullptr) nodes.push(nodes.front()->right);
                nodes.pop();
                size--;
            }
            nodeVals.push_back(levelVals);
        }

        return nodeVals;
    }

    void solve()
    {
        // My test case code
        TreeNode* leaf1 = new TreeNode(15);
        TreeNode* leaf2 = new TreeNode(7);

        TreeNode* nl21 = new TreeNode(9, nullptr, nullptr);
        TreeNode* nl22 = new TreeNode(20, leaf1, leaf2);

        TreeNode* root = new TreeNode(3, nl21, nl22);

        vector<vector<int>> output = levelOrder(root);

        for (vector<int>& v : output)
        {
            for (int x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        
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