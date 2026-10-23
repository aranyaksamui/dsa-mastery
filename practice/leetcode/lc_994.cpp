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
private:
    vector<vector<int>>& oranges;
    
public:
    int startRotting(vector<vector<int>>& nodeInfo, int row, int col, int time, int& currCount)
    {
        if (oranges[row][col] < 2 || oranges[row][col] != 2) return INT_MAX;

        queue<int> rotQueue;
        rotQueue.push(nodeInfo[row][col]);

        int insertions = 1;

        while(!rotQueue.empty())
        {
            int latestRot = rotQueue.front();
            rotQueue.pop();
            
            if (oranges[row][col] != 2) continue;

            // Down
            if (row + 1 < oranges.size() && oranges[row + 1][col] == 1)
                rotQueue.push(nodeInfo[row + 1][col]);
            
            // Up
            if (row - 1 >= 0 && oranges[row - 1][col] == 1)
                rotQueue.push(nodeInfo[row - 1][col]);
            
            // Right
            if (col + 1 < oranges[0].size() && oranges[row][col + 1] == 1)
                rotQueue.push(nodeInfo[row][col + 1]);
            
            // Left
            if (col - 1 >= 0 && oranges[row][col - 1] == 1)
                rotQueue.push(nodeInfo[row][col - 1]);
            
            
        }
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        oranges = grid;

        // Count the no. of oranges and maintain a map for the notes and it's information
        int count = 0;
        vector<vector<int>> nodeInfo(oranges.size(), vector<int>(oranges[0].size(), -1));
        
        for (int r = 0; r < oranges.size(); r++)
        {
            for (int c = 0; c < oranges[r].size(); c++)
            {
                if (oranges[r][c] < 1) continue;

                nodeInfo[r][c] = count;
                count++;
            }
        }

        // // DEBUG
        // for (pair<int, NodeInfo*> p : nodeMap)
        // {
        //     cout << p.first << endl;
        //     cout << "r: " << p.second->r << "c: " << p.second->c << "val: " << p.second->rotVal << endl;
        // }
        // // DEBUG

        int minTime = INT_MAX;

        // Multisource BFS
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] < 2) continue;

                int currCount = 1;
                int timeTaken = startRotting(nodeInfo, r, c, 0, currCount);
                
                if (count == currCount)
                    minTime = min(minTime, timeTaken);
            }
        }

        return 0;
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