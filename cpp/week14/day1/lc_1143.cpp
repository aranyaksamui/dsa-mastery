// 1143. Longest Common Subsequence

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
    void displayGrid(vector<vector<int>>& dpGrid)
    {
        for (int i = 0; i < dpGrid.size(); i++)
        {
            for (int j = 0; j < dpGrid[0].size(); j++)
            {
                cout << dpGrid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int longestCommonSequence(string text1, string text2)
    {
        vector<vector<int>> dpGrid(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i < dpGrid.size(); i++)
        {
            for (int j = 1; j < dpGrid[0].size(); j++)
            {
                if (text1[i - 1] == text2[j - 1]) dpGrid[i][j] = 1 + dpGrid[i - 1][j - 1];
                else dpGrid[i][j] = max(dpGrid[i - 1][j], dpGrid[i][j - 1]);
            }
        }

        return dpGrid[dpGrid.size() - 1][dpGrid[0].size() - 1];
    }

    void solve()
    {
        // My test case code
        // string text1 = "abcde";
        // string text2 = "ace";

        string text1 = "abc";
        string text2 = "def";

        cout << longestCommonSequence(text1, text2) << endl;

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