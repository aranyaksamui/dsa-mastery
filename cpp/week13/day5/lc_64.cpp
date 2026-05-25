// 64. Minimum Path Sum

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

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; i == 0 && j < n; j++)
                grid[i][j] = grid[i][j - 1] + grid[i][j];

            if (i == 0) continue;
            
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        }

        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n; c++)
                grid[r][c] = grid[r][c] + min(grid[r - 1][c], grid[r][c - 1]);
        }

        return grid[m - 1][n - 1];
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> grid =
        {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        };

        minPathSum(grid);
        
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