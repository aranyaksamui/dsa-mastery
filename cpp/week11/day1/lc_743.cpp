// 743. Network Delay Time

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
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> wAdjList;

        for (vector<int> wEdge : times)
        {
            pair<int, int> wDest;
            wDest.first = wEdge[1];
            wDest.second = wEdge[2];

            wAdjList[wEdge[0]].push_back(wDest);
        }

        vector<int> distance(n + 1, INT16_MAX);
        distance[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({distance[k], k});

        while (!minHeap.empty())
        {
            int currentNode = minHeap.top().second;
            minHeap.pop();

            for (pair<int, int> p : wAdjList[currentNode])
            {
                int v = p.first;
                int w = p.second;
                int neighborDist = distance[currentNode] + w;

                if (neighborDist < distance[v])
                {
                    distance[v] = distance[currentNode] + w;
                    minHeap.push({distance[v], v});
                }
            }

        }

        int minTime = *max_element(distance.begin() + 1, distance.end());
        if (minTime == INT16_MAX) return -1;

        return minTime;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> times =
        {
        //   u  v  w
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
        };
        int n = 4, k = 2;
        cout << networkDelayTime(times, n, k) << endl;

        // vector<vector<int>> times =
        // {
        // //   u  v  w
        //     {1, 2, 1},
        // };
        // int n = 2, k = 1;
        // cout << networkDelayTime(times, n, k) << endl;
        
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