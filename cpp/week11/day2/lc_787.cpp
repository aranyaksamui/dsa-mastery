// 787. Cheapest Flights Within K Stops

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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> prices(n, INT16_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> tempPrices(n, INT16_MAX);
            tempPrices = prices;

            for (vector<int>& flight : flights)
            {
                int u = flight[0], v = flight[1], price = flight[2];
                int dstPrice = prices[u] + price;

                if (dstPrice < tempPrices[v])
                    tempPrices[v] = dstPrice;
            }

            prices = tempPrices;
        }

        if (prices[dst] == INT16_MAX) return -1;
        return prices[dst];
    }

    void solve()
    {
        // My test case code
        // int n = 4, src = 0, dst = 3, k = 1;
        // vector<vector<int>> flights =
        // {
        //     {0, 1, 100},
        //     {1, 2, 100},
        //     {2, 0, 100},
        //     {1, 3, 600},
        //     {2, 3, 200}
        // };

        int n = 3, src = 1, dst = 2, k = 1;
        vector<vector<int>> flights =
        {
            {0, 1, 2},
            {1, 2, 1},
            {2, 0, 10}
        };

        cout << findCheapestPrice(n, flights, src, dst, k) << endl;

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