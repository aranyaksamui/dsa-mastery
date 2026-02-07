// 1047. Remove All Adjacent Duplicates In String

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

    string removeDuplicates(string s)
    {
        stack<char> ch;

        for (char c : s)
        {
            if (!ch.empty() && c == ch.top()) ch.pop();
            else ch.push(c);
        }

        stack<char> finalString;
        while (!ch.empty())
        {
            finalString.push(ch.top());
            ch.pop();
        }

        string res;
        while (!finalString.empty())
        {
            res.push_back(finalString.top());
            finalString.pop();
        }

        return res;
    }

    void solve()
    {
        // My test case code
        string s1 = "abbaca";
        cout << removeDuplicates(s1) << endl;

        string s2 = "azxxzy";
        cout << removeDuplicates(s2) << endl;

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