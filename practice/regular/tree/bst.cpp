// Work in progress

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

// Definition for a binary tree node
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Create a node to be inserted into the tree
TreeNode* create_node(int val)
{
    TreeNode* new_node = new TreeNode(val);
    return new_node;
}

// Insert a node at the respective position of the binary tree
void insert_node(TreeNode* root, int val)
{
    if ()
}

// Create the tree from the numbers inside the list and return the root
TreeNode* create_tree(vector<int> list)
{
    int n = list.size();

    if (n <= 0) return nullptr;

    TreeNode* root = create_node(list[0]);

    for (int i = 1; i < n; i++)
    {
        insert_node(root, list[i]);
    }
}

int main()
{
    // Sample list of numbers
    vector<int> list = {10, 23, 43, 2, 4, 29, 60, 12, 72, 43};

    // Create a binary from the numbers inside the list
    TreeNode* root = create_tree(list);


}