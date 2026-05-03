// 455. Assign Cookies

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
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (s.size() <= 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        while (true)
        {
            int greed = g[child];
            int size = s[cookie];

            if (size >= greed)
            {
                child++;
                cookie++;
            }
            else cookie++;

            if (child >= g.size() || cookie >= s.size()) break;
        }

        return child;
    }

    void solve()
    {
        // My test case code
        vector<int> g = {1, 2, 3};
        vector<int> s = {1, 1};

        cout << findContentChildren(g, s) << endl;

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