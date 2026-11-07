/*
    LeetCodE: 424. Longest Repeating Character Replacement
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
    int characterReplacement(string s, int k)
    {
        // Frequency map to store the frequency of characters in the window
        unordered_map<char, int> winCharFreq;
        
        int st = 0;         // Start pointer
        int maxFreq = 0;    // Keep track of the maximum frequency (of a character) inside the window
        int maxLen = 0;     // Keep track of the maximum length of the window (replacement + maxFreq)
        
        for (int en = 0; en < s.size(); en++)
        {
            winCharFreq[s[en]]++;
               
            maxFreq = max(maxFreq, winCharFreq[s[en]]);

            // Replacement is characters to replace to make a character longest repeating
            int replacement = ((en - st) + 1) - maxFreq;

            // If replacement is <= k we are safe and within our replacement budget k
            if (replacement <= k) maxLen = max(maxLen, (en - st) + 1);

            // If we cross the budget then repeatedly move the start pointer towards end
            while (replacement > k)
            {
                winCharFreq[s[st]]--;
                st++;
                replacement--;
            }
        }

        return maxLen;
    }

    void solve()
    {
        // My test case code
        string s = "AABABBA";
        int k = 1;

        // string s = "AABABBACCCDDDDCAAAADBBA";
        // int k = 3;

        // string s = "ABAB";
        // int k = 2;

        cout << characterReplacement(s, k) << endl;
        
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