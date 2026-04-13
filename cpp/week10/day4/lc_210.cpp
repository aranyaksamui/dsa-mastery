// 210. Course Schedule II

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
    // void debugPrint(vector<vector<int>>& adjList, vector<int>& inDegree)
    // {
    //     for (int c = 0; c < adjList.size(); c++)
    //     {
    //         cout << "course - " << c << ": ";
    //         for (int p : adjList[c])
    //             cout << p << ", ";
    //         cout << endl;
    //     }

    //     for (int dependency : inDegree)
    //     {
    //         cout << dependency << ", ";
    //     }
    // }
    // // DEBUG

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (vector<int> p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        
        queue<int> enrollQueue;
        
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0) enrollQueue.push(i);
        
        vector<int> completed;
        while (!enrollQueue.empty())
        {
            int currentCourse = enrollQueue.front();
            completed.push_back(currentCourse);
            enrollQueue.pop();

            for (int followUp : adjList[currentCourse])
            {
                inDegree[followUp]--;
                if (inDegree[followUp] == 0) enrollQueue.push(followUp);
            }
        }

        if (completed.size() == numCourses) return completed;

        return {};
    }

    void solve()
    {
        // My test case code
        int numCourses = 4;
        vector<vector<int>> prerequisites =
        {
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2}
        };
        // findOrder(numCourses, prerequisites);
        for (int x : findOrder(numCourses, prerequisites)) cout << x << " ";


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