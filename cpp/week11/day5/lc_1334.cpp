// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

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
    // // DEBUG
    // void printMatrix(vector<vector<int>>& matrix)
    // {
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         for (int j = 0; j < matrix[i].size(); j++)
    //             cout << matrix[i][j] << " ";
    //         cout << endl;
    //     }
    // }
    
    // // DEBUG

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> cityMatrix(n, vector<int>(n, INT16_MAX));

        for (int i = 0; i < n; i++) cityMatrix[i][i] = 0;

        for (vector<int>& edge : edges)
        {
            cityMatrix[edge[0]][edge[1]] = edge[2];
            cityMatrix[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (u == v || u == k || v == k) continue;
                    
                    int alternatePath = cityMatrix[u][k] + cityMatrix[k][v];
                    if (alternatePath < cityMatrix[u][v]) cityMatrix[u][v] = alternatePath;
                }
            }
        }
        
        vector<int> cityNeighbors(n, 0);
        int leastNeighbors = INT16_MAX;
        int leastNeighborsIndex = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (cityMatrix[i][j] <= distanceThreshold) cityNeighbors[i]++;

            if (cityNeighbors[i] <= leastNeighbors) 
            {
                leastNeighbors = cityNeighbors[i];
                leastNeighborsIndex = i;
            }
        }

        return leastNeighborsIndex;
    }

    void solve()
    {
        // My test case code
        // int n = 5, distanceThreshold = 2;
        // vector<vector<int>> edges =
        // {
        //     {0, 1, 2},
        //     {0, 4, 8},
        //     {1, 2, 3},
        //     {1, 4, 2},
        //     {2, 3, 1},
        //     {3, 4, 1}
        // };

        int n = 4, distanceThreshold = 4;
        vector<vector<int>> edges =
        {
            {0, 1, 3},
            {1, 2, 1},
            {1, 3, 4},
            {2, 3, 1},
        };
        
        cout << findTheCity(n, edges, distanceThreshold) << endl;

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