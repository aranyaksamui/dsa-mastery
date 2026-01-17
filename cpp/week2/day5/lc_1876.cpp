// 1876. Substrings of Size Three with Distinct Characters

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
    int countGoodSubstrings(string s)
    {
        int k = 3;
        int count = 0;
        set<char> chars;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < k)
            {
                chars.insert(s[i]);
                if (chars.size() == 3) count++;
                if (i == k - 1) chars.clear();
            }
            else
            {
                chars.insert(s[i]);
                chars.insert(s[i-1]);
                chars.insert(s[i-2]);
                if (chars.size() == 3) count++;
                chars.clear();
            }
        }
        return count;
    }

    void solve()
    {
        // My test case code
        string s = "xyzzaz";
        cout << countGoodSubstrings(s) << endl;

        // s = "aababcabc";
        // cout << countGoodSubstrings(s) << endl;

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