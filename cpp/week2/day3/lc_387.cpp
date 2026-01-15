// 387. First Unique Character in a String

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
    int firstUniqChar(string s)
    {
        vector<int> frequency(26, 0);

        for (int i = 0; i < s.size(); i++)
            frequency[s[i] - 'a']++;

        for (int i = 0; i < s.size(); i++)
            if (frequency[s[i] - 'a'] == 1) return i;

        return -1;
    }

    void solve()
    {
        // My test case code
        string s = "loveleetcode";

        cout << endl << firstUniqChar(s) << endl;

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