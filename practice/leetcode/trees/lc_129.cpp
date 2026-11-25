/*
    LeetCode 129. Sum Root to Leaf Numbers (string version)
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
    void calc(TreeNode* node, string& number)
    {
        if (node == nullptr) return;

        // Push the current number (ASCII value adjusted) of the current node 
        number.push_back('0' + node->val);

        // If left and right of current node is empty (leaf node)
        // Convert the string to number and add to total
        if (node->left == nullptr && node->right == nullptr)
        {
            total = total + stoi(number);
        }
        else
        {
            calc(node->left, number);
            calc(node->right, number);
        }

        // Always pop before reaching a parent
        number.pop_back();
    }

    int sumNumbers(TreeNode* root)
    {
        string num = "";
        calc(root, num);

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