/*
    LeetCode: 841. Keys and Rooms
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
    void visitRoom(unordered_map<int, vector<int>>& roomsMap, unordered_set<int>& visited, int visiting)
    {
        if (visited.count(visiting)) return;

        visited.insert(visiting);
        for (int x : roomsMap[visiting])
            visitRoom(roomsMap, visited, x);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size();
        unordered_set<int> visited;
        unordered_map<int, vector<int>> roomsMap;

        int i = 0;
        for (vector<int>& room : rooms)
        {
            if (i >= n) break;

            roomsMap[i] = room;
            i++;
        }
        
        visitRoom(roomsMap, visited, 0);

        for (int i = 0; i < n; i++)
            if (!visited.count(i)) return false;

        return true;
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> rooms =
        // {
        //     {1},
        //     {2},
        //     {3},
        //     {}
        // };

        vector<vector<int>> rooms =
        {
            {1, 3},
            {3, 0, 1},
            {2},
            {0}
        };

        cout << canVisitAllRooms(rooms) << endl;
        
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