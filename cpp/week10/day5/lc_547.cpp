// 547. Number of Provinces

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
    int findParent(int city)
    {
        if (parent[city] == city) return parent[city];

        parent[city] = findParent(parent[city]);
        return parent[city];
    }

    bool tryMakeUnion(int u, int v)
    {
        int parentX = findParent(u);
        int parentY = findParent(v);

        if (parentX == parentY) return false;

        if (rank[parentX] > rank[parentY])
            parent[parentY] = parentX;
        else if (rank[parentX] < rank[parentY])
            parent[parentX] = parentY;
        else
        {
            parent[parentY] = parentX;
            rank[parentX]++;
        }

        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        int totalProvinces = n;

        parent.resize(n);
        rank.resize(n, 1);

        for (int p = 0; p < n; p++) parent[p] = p;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1 && tryMakeUnion(i, j))
                {
                    totalProvinces--;
                }
            }
        }

        return totalProvinces;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> isConnected =
        {
        //   0, 1, 2   
            {1, 1, 0},  // 0
            {1, 1, 0},  // 1
            {0, 0, 1},  // 2
        };

        // findCircleNum(isConnected);
        cout << findCircleNum(isConnected) << endl;


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