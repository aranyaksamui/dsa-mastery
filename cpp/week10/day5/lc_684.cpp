// 684. Redundant Connection

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
    vector<int> representatives;
    vector<int> rank;

public:
    int findRepresentative(int node)
    {
        if (representatives[node] == node) return representatives[node];
        
        representatives[node] = findRepresentative(representatives[node]);
        return representatives[node];
    }

    bool tryMakeUnion(vector<int>& nodesOfEdge)
    {
        int repX = findRepresentative(nodesOfEdge[0]);
        int repY = findRepresentative(nodesOfEdge[1]);

        if (repX == repY) return false;

        if (rank[repX] > rank[repY])
            representatives[repY] = repX;
        else if (rank[repX] < rank[repY])
            representatives[repX] = repY;
        else
        {
            representatives[repY] = repX;
            rank[repX]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        representatives.resize(n + 1);
        rank.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) representatives[i] = i;

        for (vector<int>& nodesOfEdge : edges)
            if (!tryMakeUnion(nodesOfEdge)) return nodesOfEdge;

        return {};
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> edges =
        // {
        //     {1, 2},
        //     {2, 3},
        //     {3, 4},
        //     {1, 4},
        //     {1, 5}
        // };

        // findRedundantConnection(edges);
        // for (int x : findRedundantConnection(edges)) cout << x << " ";
        // cout << endl;
        
        // // DEBUG
        // for (int r : rank) cout << r << " ";
        // // DEBUG
        
        vector<vector<int>> edges =
        {
            {1, 2},
            {1, 3},
            {2, 3}
        };

        findRedundantConnection(edges);
        for (int x : findRedundantConnection(edges)) cout << x << " ";

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
