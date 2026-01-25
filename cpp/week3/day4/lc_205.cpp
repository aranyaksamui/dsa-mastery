// 205. Isomorphic Strings

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> bijection;
        unordered_map<char, char> revBijection;

        if (s.length() == t.length())
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (bijection.count(s[i]) && bijection.at(s[i]) != t[i] || revBijection.count(t[i]) && revBijection.at(t[i]) != s[i]) return false;
                bijection[s[i]] = t[i];
                revBijection[t[i]] = s[i];
                cout << bijection.at(s[i]) << " " << revBijection.at(t[i]) << endl;
            }
        }

        return true;
    }

    void solve()
    {
        // My test case code
        // string s = "egg";
        // string t = "add";

        // cout << isIsomorphic(s, t) << endl;

        // string s = "foo";
        // string t = "bar";

        // cout << isIsomorphic(s, t) << endl;

        // string s = "paper";
        // string t = "title";

        // cout << isIsomorphic(s, t) << endl;

        string s = "badc";
        string t = "baba";

        cout << isIsomorphic(s, t) << endl;



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