/*
    LeetCode: 1791. Find Center of Star Graph
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
    int findCenter(vector<vector<int>>& edges)
    {
        unordered_map<int, int> edgeCount;

        for (vector<int>& edge : edges)
        {
            edgeCount[edge[0]]++;
            edgeCount[edge[1]]++;
        }

        for (pair<int, int> p : edgeCount)
            if (p.second > 1) return p.first;

        return 1;
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> edges =
        // {
        //     {1, 2},
        //     {2, 3},
        //     {4, 2}
        // };

        vector<vector<int>> edges =
        {
            {1, 2},
            {5, 1},
            {1, 3},
            {1, 4}
        };

        cout << findCenter(edges) << endl;

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