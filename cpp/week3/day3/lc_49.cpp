// 49. Group Anagrams

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
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> stringGroups;

        for (string s : strs)
        {
            string ts = s;
            sort(ts.begin(), ts.end());
            anagrams[ts].push_back(s);
        }

        for (auto p : anagrams) stringGroups.push_back(p.second);

        return stringGroups;
    }

    void solve()
    {
        // My test case code
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        groupAnagrams(strs);

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