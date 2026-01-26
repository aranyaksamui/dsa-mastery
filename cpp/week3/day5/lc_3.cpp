// 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

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
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet;
        int exclude = 0;
        int include = 0;
        int charCount = 0;

        while (include < s.length())
        {
            if (!charSet.count(s[include]))
            {
                charSet.insert(s[include]);
                include++;
            }
            else if (charSet.count(s[include]))
            {
                if (s[exclude] != s[include] && exclude < include)
                {
                    charSet.erase(s[exclude]);
                    exclude++;
                    continue;
                }
                charSet.erase(s[exclude]);
                exclude++;
                charSet.insert(s[include]);
                include++;
            }

            if (charCount < include - exclude) charCount = include - exclude;
        }
        
        return charCount;
    }

    void solve()
    {
        // My test case code
        // string s = "abcabcbb";
        // cout << lengthOfLongestSubstring(s) << endl;

        string s = "bbbbb";
        cout << lengthOfLongestSubstring(s) << endl;

        // string s = "pwwkew";
        // cout << lengthOfLongestSubstring(s) << endl;

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