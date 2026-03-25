// 77. Combinations

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
private:
    vector<vector<int>> combination;
public:
    void combineHelper(const int& n, const int& k, vector<int>& currentCombi, int i)
    {
        if (currentCombi.size() == k)
        {
            combination.push_back(currentCombi);
            return;
        }

        for (; i <= n; i++)
        {
            currentCombi.push_back(i);
            combineHelper(n, k, currentCombi, i + 1);
            currentCombi.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> currentCombi;
        int i = 1;

        combineHelper(n, k, currentCombi, i);

        return combination;
    }

    void solve()
    {
        // My test case code
        int n = 4, k = 2;

        for (vector<int> v : combine(n, k))
        {
            for(int x : v) cout << x << ", ";
            cout << endl;
        }
        
        
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