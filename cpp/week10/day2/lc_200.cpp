// 200. Number of Islands

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
    void printGrid(vector<vector<char>>& grid)
    {
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
                cout << grid[row][col] << " ";
            cout << endl;
        }
    }
    // DEBUG

    void destroyLand(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';

        if (col - 1 >= 0 && grid[row][col - 1] == '1') destroyLand(grid, row, col - 1);
        if (col + 1 < grid[row].size() && grid[row][col + 1] == '1') destroyLand(grid, row, col + 1);
        if (row - 1 >= 0 && grid[row - 1][col] == '1') destroyLand(grid, row - 1, col);
        if (row + 1 < grid.size() && grid[row + 1][col] == '1') destroyLand(grid, row + 1, col);
        
        return;
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int islandCount = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[row].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    islandCount++;
                    
                    destroyLand(grid, row, col);
                }
            }
        }

        return islandCount;
    }

    void solve()
    {
        // My test case code
        // vector<vector<char>> grid =
        // {
        //     {'1', '1', '1', '1', '0'},
        //     {'1', '1', '0', '1', '0'},
        //     {'1', '1', '0', '0', '0'},
        //     {'0', '0', '0', '0', '0'},
        // };
        
        // cout << numIslands(grid) << endl;

        vector<vector<char>> grid =
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        
        cout << numIslands(grid) << endl;

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