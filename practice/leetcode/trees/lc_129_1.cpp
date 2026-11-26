/*
    LeetCode 129. Sum Root to Leaf Numbers (only number version)
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
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    int total = 0;

public:
    void calc(TreeNode* node, int curr)
    {
        if (node == nullptr) return;

        // Update current for current node
        curr = curr * 10 + node->val;

        // If current node is leaf then add total with current value
        if (node->left == nullptr && node->right == nullptr)
        {
            total = total + curr;
        }
        else
        {
            calc(node->left, curr);
            calc(node->right, curr);
        }
    }

    int sumNumbers(TreeNode* root)
    {
        int curr = 0;
        calc(root, curr);

        return total;
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