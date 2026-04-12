// 767. Reorganize String

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
    string reorganizeString(string s)
    {
        unordered_map<char, int> charFreqMap;

        for (char c : s) charFreqMap[c]++;

        priority_queue<pair<int, char>> maxCharFreq;
        for (pair<char, int> charFreq : charFreqMap)
        {
            pair<int, char> thisCharFreq;
            thisCharFreq.first = charFreq.second;
            thisCharFreq.second = charFreq.first;

            maxCharFreq.push(thisCharFreq);
        }

        string newString = "";
        pair<int, char> prev = {0, '#'};
        char prevChar;

        while (!maxCharFreq.empty())
        {
            pair<int, char> topChar = maxCharFreq.top();
            maxCharFreq.pop();

            newString.push_back(topChar.second);
            topChar.first--;

            if (prev.first > 0) maxCharFreq.push(prev);

            prev = topChar;
        }

        if (newString.length() == s.length()) return newString;
        else return "";

        return newString;
    }

    void solve()
    {
        // My test case code
        // string s = "aab";
        // for (char c : reorganizeString(s)) cout << c << "";

        // string s = "aaab";
        // for (char c : reorganizeString(s)) cout << c << "";

        string s = "vvvlo";
        for (char c : reorganizeString(s)) cout << c << "";

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