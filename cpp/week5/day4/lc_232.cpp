// 232. Implement Queue using Stacks

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

using namespace std;

// This function speeds up input/output operations
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class MyQueue
{
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int item = s2.top();
        s2.pop();
        
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return item;
    }

    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int item = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return item;
    }

    bool empty()
    {
        if (s1.empty()) return true;
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
        MyQueue* obj = new MyQueue();
        obj->push(1);
        obj->push(2);
        cout << obj->peek() << endl;
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