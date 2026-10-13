/*
    LeetCode: 133. Clone Graph
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

class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

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
    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> nodeMap;
        queue<Node*> nodeQueue;
        
        Node* clone = new Node(node->val);
        nodeMap[node] = clone;
        
        nodeQueue.push(node);
        
        while (!nodeQueue.empty())
        {
            Node* currNode = nodeQueue.front();
            Node* currClone = nodeMap[currNode];

            for (Node* neighbor : currNode->neighbors)
            {
                if (!nodeMap.count(neighbor))
                {
                    Node* neighborClone = new Node(neighbor->val);
                    nodeMap[neighbor] = neighborClone;
                    nodeQueue.push(neighbor);
                }

                currClone->neighbors.push_back(nodeMap[neighbor]);
            }

            nodeQueue.pop();
        }

        return clone;
    }

    void solve()
    {
        // My test case code
        
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