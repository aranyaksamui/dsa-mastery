// 121. Best Time to Buy and Sell Stock

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

// Definition for singly-linked list for Linked List problems.
// struct ListNode
// {
//     int val;
//     ListNode *next;

//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// Definition for a binary tree node.
// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
    int maxProfit(vector<int>& prices)
    {
        int buy = 0;
        int sell = 1;
        int maxReturn = 0;

        for (; sell < prices.size() && sell >= buy; sell++)
        {
            if (prices[sell] < prices[buy])
                buy = sell;

            maxReturn = max(maxReturn, prices[sell] - prices[buy]);
        }

        return maxReturn;
    }

    void solve()
    {
        // My test case code
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        // vector<int> prices = {7, 6, 4, 3, 1};

        cout << maxProfit(prices) << endl;

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