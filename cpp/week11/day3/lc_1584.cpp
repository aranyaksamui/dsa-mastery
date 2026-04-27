// 1584. Min Cost to Connect All Points

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
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();

        unordered_map<int, vector<vector<int>>> adjList;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjList[i].push_back({w, j});
                adjList[j].push_back({w, i});
            }
        }

        // DEBUG
        for (auto& e : adjList)
        {
            cout << e.first << ": ";
            for (vector<int> v : e.second) cout << "{" << v[0] << ", " << v[1] << "}";
            cout << endl;
        }
        cout << endl;
        // DEBUG
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0});   // w, u
        
        vector<bool> visited(n, false);
        int totalCost = 0;
        int connectedNodes = 0;

        while (connectedNodes < n)
        {
            int w = minHeap.top()[0];
            int v = minHeap.top()[1];
            minHeap.pop();

            if (visited[v] == true) continue;

            visited[v] = true;
            connectedNodes++;

            totalCost += w;

            for (vector<int> arr : adjList[v]) minHeap.push(arr);
        }

        return totalCost;
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> points =
        // {
        //     {0, 0},     // 0
        //     {2, 2},     // 1
        //     {3, 10},    // 2
        //     {5, 2},     // 3
        //     {7, 0}      // 4
        // };
        vector<vector<int>> points =
        {
            {0, 0},      // 0
            {1, 1},      // 1
            {1, 0},      // 2
            {-1, 1},     // 3
        };
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