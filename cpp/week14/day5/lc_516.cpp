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

    int longestPalindromeSubseq(string& s)
    {
        vector<vector<int>> dpGrid(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++) dpGrid[i][i] = 1;

        
        for (int i = s.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j]) dpGrid[i][j] = 2 + dpGrid[i + 1][j - 1];
                else dpGrid[i][j] = max(dpGrid[i + 1][j], dpGrid[i][j - 1]);
            }
        }

        return dpGrid[0][s.size() - 1];
    }

    void solve()
    {
        // My test case code
        string s = "bbbab";
        
        longestPalindromeSubseq(s);

        
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