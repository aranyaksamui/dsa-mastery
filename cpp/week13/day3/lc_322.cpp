// 322. Coin Change

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
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount <= 0) return 0;

        vector<int> dp(amount + 1, INT16_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < dp.size(); i++)
        {
            for (int coin : coins)
            {
                if (coin > i) continue;

                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        if (dp[amount] < INT16_MAX) return dp[amount];
        return -1;
    }

    void solve()
    {
        // My test case code
        vector<int> coins = {1, 2, 5};
        int amount = 11;

        cout << coinChange(coins, amount) << endl;
        
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