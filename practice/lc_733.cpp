// 733. Flood Fill

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
    void displayGrid(const vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++) cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    // DEBUG

    void floodFillHelper(vector<vector<int>>& image, int r, int c, int& color)
    {
        int initColor = image[r][c];
        image[r][c] = color;
        
        if (r + 1 < image.size() && image[r + 1][c] == initColor)
            floodFillHelper(image, r + 1, c, color);
        if (r - 1 >= 0 && image[r - 1][c] == initColor)
            floodFillHelper(image, r - 1, c, color);
        if (c + 1 < image[r].size() && image[r][c + 1] == initColor)
            floodFillHelper(image, r, c + 1, color);
        if (c - 1 >= 0 && image[r][c - 1] == initColor)
            floodFillHelper(image, r, c - 1, color);
        
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        // displayGrid(image);
        if (image[sr][sc] == color) return image;

        floodFillHelper(image, sr, sc, color);

        return image;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> image = 
        {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
        };
        int sr = 1, sc = 1, color = 2;
        // vector<vector<int>> image = 
        // {
        //     {0, 0, 0},
        //     {0, 0, 0},
        //     {0, 0, 0}
        // };
        // int sr = 0, sc = 0, color = 0;

        displayGrid(floodFill(image, sr, sc, color));

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