// 344. Reverse String (Recursive)

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
    void revStrHelper(vector<char>& s, int start, int end)
    {
        if (start >= end) return;
        
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        return revStrHelper(s, ++start, --end);
    }

    void reverseString(vector<char>& s)
    {
        int start = 0;
        int end = s.size() - 1;

        revStrHelper(s, start, end);
    }

    void solve()
    {
        // My test case code
        vector<char> s = {'h', 'e', 'l', 'l', 'o'};
        reverseString(s);
        for (char x : s) cout << x << " ";

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