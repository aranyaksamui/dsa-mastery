// 242. Valid Anagram

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
    bool isAnagram(string s, string t)
    {
        int frequency[26] = {0};

        for (int i = 0; i < s.size() || i < t.size(); i++)
        {
            if (i < s.size()) frequency[s[i] - 'a']++;
            if (i < t.size()) frequency[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] != 0) return false;
        }

        return true;
    }

    void solve()
    {
        // My test case code
        string s = "rat";
        string t = "car";
        cout << endl << isAnagram(s, t) << endl;

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