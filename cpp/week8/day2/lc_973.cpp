// 973. K Closest Points to Origin

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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<int, vector<int>>> sortedPoints;

        for (vector<int> point : points)
        {
            int dist = (point[0] * point[0]) + (point[1] * point[1]);
            
            pair<int, vector<int>> distPoint;
            distPoint.first = dist;
            distPoint.second = point;

            sortedPoints.push(distPoint);
            
            if (sortedPoints.size() > k) sortedPoints.pop();
        }

        vector<vector<int>> closestPoints;

        while (!sortedPoints.empty())
        {
            closestPoints.push_back(sortedPoints.top().second);
            sortedPoints.pop();
        }

        return closestPoints;
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
        // int k = 2;

        vector<vector<int>> points = {{2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}};
        int k = 1;

        for (vector<int> point : kClosest(points, k))
        {
            cout << point[0] << ", " << point[1] << endl;
        }

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