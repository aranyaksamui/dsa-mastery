// 20. Valid Parentheses

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

// Solution Class (Like LeetCode)
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() <= 1) return false;

        stack<char> st;
        unordered_map<char, char> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for (char c : s)
        {
            if (brackets.count(c))
                st.push(c);
            else if (!st.empty() && c == brackets[st.top()] && brackets.count(st.top()))
            {
                st.pop();
            }
            else return false;
        }

        if (st.empty()) return true;
        else return false;
    }

    void solve()
    {
        // My test case code
        string s1 = "()";
        cout << isValid (s1) << endl;

        string s2 = "()[]{}";
        cout << isValid (s2) << endl;

        string s3 = "(]";
        cout << isValid (s3) << endl;

        string s4 = "([])";
        cout << isValid (s4) << endl;

        string s5 = "([)]";
        cout << isValid (s5) << endl;

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