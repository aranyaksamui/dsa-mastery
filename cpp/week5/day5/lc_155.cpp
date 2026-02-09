// 155. Min Stack

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

class MinStack
{
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int x)
    {
        st.push(x);
        if (!minStack.empty() && st.top() <= minStack.top()) minStack.push(x);
        else if (minStack.empty()) minStack.push(x);
    }

    void pop()
    {
        if (st.top() == minStack.top())
        {
            st.pop();
            minStack.pop();
        }
        else st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    void solve()
    {
        // My test case code
        MinStack* ms = new MinStack();
        ms->push(-2);
        ms->push(0);
        ms->push(-3);
        cout << ms->getMin() << endl;
        ms->pop();
        cout << ms->top() << endl;
        cout << ms->getMin() << endl;

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