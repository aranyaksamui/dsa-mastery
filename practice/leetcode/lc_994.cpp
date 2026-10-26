/*
    LeetCode: 994. Rotting Oranges
*/

#include <bits/stdc++.h>

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
    int orangesRotting(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Process the grid and ignore empty cells, count fresh oranges and push rotten oranges to a queue
        queue<pair<int, int>> rotQueue;
        int freshCount = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 0) continue;
                else if (grid[r][c] == 1) freshCount++;
                else if (grid[r][c] == 2) rotQueue.push({r, c});
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;

        // Direction vector for concise boundary checking
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        // Find the minimum time for all oranges to rot
        while (!rotQueue.empty() && freshCount > 0)
        {
            int currRot = rotQueue.size();
            minutes++;

            // Process the no. of rotten oranges currently in queue in the current minute
            for (int i = 0; i < currRot; i++)
            {
                pair<int, int> f = rotQueue.front();
                rotQueue.pop();

                int row = f.first;
                int col = f.second;

                // Process the 4 diagonals of the current rotten orange
                for (int d = 0; d < 4; d++)
                {
                    int nRow = row + dRow[d];
                    int nCol = col + dCol[d];

                    if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 1)
                    {
                        grid[nRow][nCol] = 2;
                        freshCount--;
                        rotQueue.push({nRow, nCol});
                    }
                }
            }
        }

        if (freshCount > 0) return -1;

        return minutes;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> grid =
        {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
        };

        cout << orangesRotting(grid) << endl;

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