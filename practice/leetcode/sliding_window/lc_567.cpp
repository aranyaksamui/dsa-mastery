/*
    LeetCode: 567. Permutation in String
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
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);

        // Fill the two maps with their frequencies with respect to s1
        for (int c = 0; c < s1.size(); c++)
        {
            s1Map[s1[c] - 'a']++;
            s2Map[s2[c] - 'a']++;
        }

        // If the characters in both window are same frequencies at start return true
        if (s1Map == s2Map) return true;

        // Start the window next to the last index of s1 up until the last index of s2
        bool areEqual = false;
        for (int i = s1.size(); i < s2.size(); i++)
        {
            char in = s2[i];
            s2Map[in - 'a']++;

            char out = s2[i - s1.size()];
            s2Map[out - 'a']--;

            if (s1Map == s2Map) areEqual = true;
        }

        return areEqual;
    }

    void solve()
    {
        // My test case code
        // string s1 = "ab";
        // string s2 = "eidbaooo";

        string s1 = "acd";
        string s2 = "dcda";

        cout << checkInclusion(s1, s2) << endl;
        
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