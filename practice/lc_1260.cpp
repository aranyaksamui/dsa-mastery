/*
    LeetCode: 1260. Shift 2D Grid
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
    void displayGrid(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
                cout << grid[i][j] << ", ";
            cout << endl;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m * n == k) return grid;

        vector<vector<int>> resultGrid(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int y = (j + k) % n;
                int x = (i + ((int) (j + k) / n)) % m;
                resultGrid[x][y] = grid[i][j];
            }
        }

        return resultGrid;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> grid =
        {
            {3, 8, 1, 9},
            {19, 7, 2, 5},
            {4, 6, 11, 10},
            {12, 0, 21, 13}
        };
        int k = 4;

        shiftGrid(grid, k);

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