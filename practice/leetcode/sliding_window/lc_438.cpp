/*
    LeetCode: 438. Find All Anagrams in a String
*/

#include <bits/stdc++.h>

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
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size()) return {};

        // Get the window length for the anagram (will be the string size of p)
        int winLen = p.size();

        // Create a vector for 26 chars and fillup with the character frequencies in p
        vector<int> stencil(26);
        for (char c : p) stencil[c - 'a']++;

        // Window to check frequencies against the stencil
        vector<int> window(26);

        // Indicies array to store the start indices of the anagrams
        vector<int> indices;

        // First winLen elements
        int en = 0;
        for (; en < winLen; en++)
            window[s[en] - 'a']++;
        
        // Check first winLen elements
        if (window == stencil) indices.push_back(winLen - en);

        int st = en - winLen;
        for (; en < s.size(); en++)
        {
            window[s[st] - 'a']--;
            window[s[en] - 'a']++;

            if (window == stencil) indices.push_back(st + 1);

            st++;
        }

        return indices;
    }

    void solve()
    {
        // My test case code
        string s = "cbaebabacd";
        string p = "abc";

        for (int x : findAnagrams(s, p)) cout << x << " ";
        
        cout << endl;
        
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