// 1584. Min Cost to Connect All Points (Kruskal's approach)

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
    vector<int> parent;
    vector<int> rank;

public:
    int findParent(int node) 
    {
        if (parent[node] == node) return parent[node];

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    bool tryMakeUnion(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return false;
        
        if (rank[parentU] > rank[parentV])
            parent[parentV] = parentU;
        else if (rank[parentU] < rank[parentV])
            parent[parentU] = parentV;
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }

        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        vector<vector<int>> edgeList;
        
        for (int u = 0; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int w = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                edgeList.push_back({w, u, v});
            }
        }

        sort(edgeList.begin(), edgeList.end());

        rank.resize(n, 1);
        parent.resize(n);
        for (int p = 0; p < n; p++) parent[p] = p;

        int connectedNodes = 0;
        int totalCost = 0;

        int i = 0;
        while (connectedNodes < n - 1 && i < edgeList.size())
        {
            int cost = edgeList[i][0];
            if (tryMakeUnion(edgeList[i][1], edgeList[i][2]))
            {
                connectedNodes++;
                totalCost += cost;
            }
            i++;
        }

        return totalCost;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> points =
        {
            {0, 0},     // 0
            {2, 2},     // 1
            {3, 10},    // 2
            {5, 2},     // 3
            {7, 0}      // 4
        };
        // vector<vector<int>> points =
        // {
        //     {0, 0},      // 0
        //     {1, 1},      // 1
        //     {1, 0},      // 2
        //     {-1, 1},     // 3
        // };
        // minCostConnectPoints(points);
        cout << minCostConnectPoints(points) << endl;

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