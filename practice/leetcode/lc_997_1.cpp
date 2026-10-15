/*
    LeetCode: 997. Find the Town Judge
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
    int findJudge(int n, vector<vector<int>>& trust)
    {
        if (n == 1) return 1;

        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        for (vector<int>& t : trust)
        {
            inDegree[t[1]]++;
            outDegree[t[0]]++;
        }

        for (int i = 1; i <= n; i++)
            if (inDegree[i] == n - 1 && outDegree[i] == 0) return i;

        return -1;
    }

    void solve()
    {
        // My test case code
        // int n = 3;
        // vector<vector<int>> trust = 
        // {
        //     {1, 3},
        //     {2, 3}
        // };
        int n = 3;
        vector<vector<int>> trust = 
        {
            {1, 3},
            {2, 3},
            {3, 1}
        };
        // int n = 4;
        // vector<vector<int>> trust = 
        // {
        //     {1, 3},
        //     {1, 4},
        //     {2, 3},
        //     {2, 4},
        //     {4, 3}
        // };

        findJudge(n, trust);
        
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