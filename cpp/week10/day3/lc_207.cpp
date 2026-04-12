// 207. Course Schedule

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

enum NodeState
{
    UNVISITED,
    VISITING,
    VISITED
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    bool courseFinisher(unordered_map<int, vector<int>>& adjList, vector<int>& courseNodeState, int currentCourse)
    {
        if (courseNodeState[currentCourse] == NodeState::VISITED) return true;
        if (courseNodeState[currentCourse] == NodeState::VISITING) return false;
        
        courseNodeState[currentCourse] = NodeState::VISITING;

        if (adjList.count(currentCourse))
        {
            for (int followUp : adjList[currentCourse])
                if (!courseFinisher(adjList, courseNodeState, followUp)) return false;
        }

        courseNodeState[currentCourse] = NodeState::VISITED;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if (prerequisites.empty()) return true;

        unordered_map<int, vector<int>> adjList;
        for (vector<int>& prereq : prerequisites)
        {
            if (prereq[1] == prereq[0]) return false;
            adjList[prereq[1]].push_back(prereq[0]);
        }

        vector<int> courseNodeState(numCourses, NodeState::UNVISITED);

        for (pair<int, vector<int>> p : adjList)
        {
            if (courseNodeState[p.first] == NodeState::UNVISITED)
                if (!courseFinisher(adjList, courseNodeState, p.first)) return false;
        }

        return true;
    }

    void solve()
    {
        // My test case code
        // int numCourses = 4;
        // vector<vector<int>> prerequisites =
        // {
        //     {0, 3},
        //     {1, 3},
        //     {2, 0},
        //     {2, 1},
        // };

        int numCourses = 6;
        vector<vector<int>> prerequisites =
        {
            {1, 0},
            {1, 2},
            {3, 1},
            {2, 3},
            {2, 4},
            {4, 5},
            {2, 5},
        };

        cout << canFinish(numCourses, prerequisites) << endl;


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