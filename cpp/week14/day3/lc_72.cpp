// 72. Edit Distance

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

    int minDistance(string word1, string word2)
    {
        vector<vector<int>> distGrid(word1.size() + 1, vector<int>(word2.size() + 1, INT16_MAX));

        for (int i = 0; i < distGrid.size(); i++)
        {
            for (int j = 0; i == 0 && j < distGrid[0].size(); j++)
                distGrid[i][j] = j;
            
            if (i == 0) continue;

            distGrid[i][0] = i;
        }

        for (int i = 1; i < distGrid.size(); i++)
        {
            for (int j = 1; j < distGrid[0].size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    distGrid[i][j] = 0 + distGrid[i - 1][j - 1];
                else
                    distGrid[i][j] = 1 + min(distGrid[i - 1][j - 1], min(distGrid[i - 1][j], distGrid[i][j - 1]));
            }
        }

        return distGrid[distGrid.size() - 1][distGrid[0].size() - 1];
    }

    void solve()
    {
        // My test case code
        string word1 = "horse";
        string word2 = "ros";

        minDistance(word1, word2);
        
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