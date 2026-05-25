// 62. Unique Paths

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
        for (vector<int>& row : dpGrid)
        {
            for (int x : row) cout << x << " ";
            cout << endl;
        }
    }
    // DEBUG

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dpGrid(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; i == 0 && j < n; j++) dpGrid[i][j] = 1;
            dpGrid[i][0] = 1;
        }

        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n; c++) 
                dpGrid[r][c] = dpGrid[r - 1][c] + dpGrid[r][c - 1];
        }

        return dpGrid[m - 1][n - 1];
    }

    void solve()
    {
        // My test case code
        // int m = 3, n = 7;

        int m = 4, n = 4;

        cout << uniquePaths(m, n) << endl;

        
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