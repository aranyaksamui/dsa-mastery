/*
    LeetCode: 3. Longest Substring Without Repeating Characters
*/

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
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        int start = 0;
        int end = 0;

        unordered_set<char> uniqueChars;
        int maxLength = 0;

        while (start <= end && end < s.size())
        {
            if (!uniqueChars.count(s[end]))
            {
                uniqueChars.insert(s[end]);
                end++;
            }
            else if (uniqueChars.count(s[end]))
            {
                maxLength = max(maxLength, (int) uniqueChars.size());
                uniqueChars.erase(s[start]);
                start++;
            }
        }

        maxLength = max(maxLength, (int) uniqueChars.size());

        return maxLength;
    }

    void solve()
    {
        // My test case code
        // string s = "pwwkew";
        // string s = "abcabcbb";
        string s = "mq";

        cout << lengthOfLongestSubstring(s) << endl;
        
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