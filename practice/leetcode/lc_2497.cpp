/*
    LeetCode: 2497. Maximum Star Sum of a Graph
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
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        // If it's a completely disconnected graph
        if (edges.size() == 0)
        {
            int max = INT_MIN;
            for (int x : vals)
                if (x > max) max = x;
            
            return max;
        }

        // Create an adjacency list from the edges array
        unordered_map<int, vector<int>> adjList;
        for (vector<int> edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int globalMax = INT_MIN;

        // Take every node as center and check the global max upto k neighbors
        for (int center = 0; center < vals.size(); center++)
        {
            // Use a max heap to sort values of star center neighbors at insert time
            // Insert the neighbors of star center and sum the first k elements (largest in val)
            priority_queue<int> maxValHeap;
            vector<int>& neighbors = adjList[center];
            for (int neighbor : neighbors)
                maxValHeap.push(vals[neighbor]);

            // Maintain a count variable to take top k elements from the heap exclusive of negatives
            int maxSum = vals[center];
            int count = 0;
            while (!maxValHeap.empty() && count < k)
            {
                int topVal = maxValHeap.top();
                maxValHeap.pop();
                
                if (topVal <= 0) break;

                maxSum += topVal;
                count++;
            }

            globalMax = max(globalMax, maxSum);
        }

        return globalMax;
    }

    void solve()
    {
        // My test case code
        vector<int> vals = {1, 2, 3, 4, 10, -10, -20};
        vector<vector<int>> edges = {
            {0, 1},
            {1, 2},
            {1, 3},
            {3, 4},
            {3, 5},
            {3, 6}
        };
        int k = 2;

        cout << maxStarSum(vals, edges, k) << endl;

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