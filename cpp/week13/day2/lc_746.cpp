// 746. Min Cost Climbing Stairs

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
    void minCostHelper(vector<int>& cost, vector<int>& memo, int i)
    {
        if (i >= cost.size())
        {
            memo[i] = min(memo[i - 2], memo[i - 1]);
            return;
        }

        memo[i] = min(memo[i - 2], memo[i - 1]) + cost[i];

        minCostHelper(cost, memo, i + 1);
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        vector<int> memo(n + 1, -1);
        memo[0] = cost[0];
        memo[1] = cost[1];

        int i = 2;

        minCostHelper(cost, memo, i);

        return memo[n];
    }

    void solve()
    {
        // My test case code
        vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        
        // vector<int> cost = {10, 15, 20};

        cout << minCostClimbingStairs(cost) << endl;

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