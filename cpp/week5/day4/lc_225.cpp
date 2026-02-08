// 225. Implement Stack using Queues

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

class MyStack
{
    queue<int> q1;
public:
    MyStack() {}
    
    void push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {        
        int item = q1.front();
        q1.pop();

        return item;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        if (q1.empty()) return true;
        else return false;
    }
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    void solve()
    {
        // My test case code
        MyStack* obj = new MyStack();
        obj->push(1);
        obj->push(2);
        cout << obj->top() << endl;
        cout << obj->pop() << endl;
        cout << obj->empty() << endl;

        
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