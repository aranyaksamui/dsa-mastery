/*
    100. Same Tree
*/

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
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // Base case 1: If nodes of both the tree are null then return true
        if (p == nullptr && q == nullptr) return true;
        
        // Base case 2: If nodes of either the tree are null or their values don't match then return false
        if (p == nullptr || q == nullptr || p->val != q->val) return false;

        // Recursively traverse the entire tree from both sides (DFS) if nodes and values are same and not null
        // AND the return value to get the final value that propagates upward
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    void solve()
    {
        // My test case code
        TreeNode* pl11 = new TreeNode(2);
        TreeNode* pr12 = new TreeNode(3);
        TreeNode* proot = new TreeNode(1, pl11, pr12);

        TreeNode* ql11 = new TreeNode(2);
        TreeNode* qr12 = new TreeNode(3);
        TreeNode* qroot = new TreeNode(1, ql11, qr12);

        cout << isSameTree(proot, qroot) << endl;
        
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