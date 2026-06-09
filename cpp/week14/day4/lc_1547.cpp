// 1547. Minimum Cost to Cut a Stick

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
    // DEBUG
    void displayGrid(vector<vector<int>>& dpGrid)
    {
        for (int i = 0; i < dpGrid.size(); i++)
        {
            for (int j = 0; j < dpGrid[0].size(); j++)
                cout << dpGrid[i][j] << " ";
            cout << endl;
        }
    }
    // DEBUG

    int minCost(int n, vector<int>& cuts)
    {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> cutsDp(cuts.size(), vector<int>(cuts.size(), 0));
        
        sort(cuts.begin(), cuts.end());
        
        int start = 0;
        int end = n;
        int m = cuts.size();

        for (int len = 2; len < m; len++)
        {
            for (int i = 0; i < m - len; i++)
            {
                int j = i + len;
                cutsDp[i][j] = INT32_MAX;

                for (int k = i + 1; k < j; k++)
                {
                    int cost = cutsDp[i][k] + cutsDp[k][j] + (cuts[j] - cuts[i]);
                    cutsDp[i][j] = min(cutsDp[i][j], cost);
                }
            }
        }

        return cutsDp[0][m - 1];
    }

    void solve()
    {
        // My test case code
        int n = 7;
        vector<int> cuts = {1, 3, 4, 5};
        
        cout << minCost(n, cuts) << endl;

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