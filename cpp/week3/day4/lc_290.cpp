// 290. Word Pattern

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
    bool wordPattern(string pattern, string s)
    {
        stringstream ss(s);
        unordered_map<char, string> bijection;
        unordered_map<string, char> revBijection;
        string word;
        int i = 0;
        int wordCount = 0;

        while (ss >> word) wordCount++;
        if (wordCount != pattern.length()) return false;

        ss.clear();
        ss.seekg(0);

        cout << wordCount << " " << pattern.length() << endl;

        while (ss >> word && i < pattern.length())
        {

            if (bijection.count(pattern[i]) && bijection.at(pattern[i]) != word) return false;
            if (revBijection.count(word) && revBijection.at(word) != pattern[i]) return false;
            bijection[pattern[i]] = word;
            revBijection[word] = pattern[i];
            i++;
        }

        return true;
    }

    void solve()
    {
        // My test case code
        // string pattern = "abba";
        // string s = "dog cat cat dog";
        // cout << wordPattern(pattern, s) << endl;

        string pattern = "abba";
        string s = "dog dog dog dog";
        cout << wordPattern(pattern, s) << endl;

        // string pattern = "aaa";
        // string s = "aa aa aa aa";
        // cout << wordPattern(pattern, s) << endl;

        // string pattern = "abba";
        // string s = "dog cat cat fish";
        // cout << wordPattern(pattern, s) << endl;

        // string pattern = "aaaa";
        // string s = "dog cat cat dog";
        // cout << wordPattern(pattern, s) << endl;

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