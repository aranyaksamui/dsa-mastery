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
    bool validPathHelper(unordered_map<int, vector<int>>& adjList, vector<int>& visited, int current, int d)
    {
        if (current == d) return true;

        visited[current] = 1;

        bool hasValidPath = false;

        for (int x : adjList[current])
        {
            if (visited[x] == 1) continue;

            hasValidPath = validPathHelper(adjList, visited, x, d);
            if (hasValidPath) return hasValidPath;
        }

        return hasValidPath;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adjList;

        for (vector<int> e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);

        return validPathHelper(adjList, visited, source, destination);
    }

    void solve()
    {
        // My test case code
        // int n = 3;
        // vector<vector<int>> edges =
        // {
        //     {0, 1},
        //     {1, 2},
        //     {2, 0}
        // };
        // int source = 0;
        // int destination = 2;

        int n = 10;
        vector<vector<int>> edges =
        {
            {4, 3},
            {1, 4},
            {4, 8},
            {1, 7},
            {6, 4},
            {4, 2},
            {7, 4},
            {4, 0},
            {0, 9},
            {5, 4}
        };
        int source = 0;
        int destination = 9;

        // int n = 10;
        // vector<vector<int>> edges =
        // {
        //     {0, 7},
        //     {0, 8},
        //     {6, 1},
        //     {2, 0},
        //     {0, 4},
        //     {5, 8},
        //     {4, 7},
        //     {1, 3},
        //     {3, 5},
        //     {6, 5}
        // };
        // int source = 7;
        // int destination = 5;

        cout << validPath(n, edges, source, destination) << endl;
        
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