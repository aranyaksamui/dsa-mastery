// 695. Max Area of Island

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
    int destroyIsland(vector<vector<int>>& grid, int row, int col, int& islandArea)
    {
        islandArea++;

        grid[row][col] = 0;

        if (row - 1 >= 0 && grid[row - 1][col] == 1) destroyIsland(grid, row - 1, col, islandArea);
        if (row + 1 < grid.size() && grid[row + 1][col] == 1) destroyIsland(grid, row + 1, col, islandArea);
        if (col - 1 >= 0 && grid[row][col - 1] == 1) destroyIsland(grid, row, col - 1, islandArea);
        if (col + 1 < grid[row].size() && grid[row][col + 1] == 1) destroyIsland(grid, row, col + 1, islandArea);

        return islandArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxIslandArea = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    int currentIslandArea = 0;
                    currentIslandArea = destroyIsland(grid, row, col, currentIslandArea);

                    if (currentIslandArea > maxIslandArea) maxIslandArea = currentIslandArea;
                }
            }
        }

        return maxIslandArea;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> grid =
        {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
        };

        cout << maxAreaOfIsland(grid) << endl;

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