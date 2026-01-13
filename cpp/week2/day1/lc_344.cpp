#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

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
    void reverseString(vector<char>& s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end)
        {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;

            start++;
            end--;
        }
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