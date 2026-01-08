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
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int maxWealth = 0;
        int sum;
        for (vector<int>& banks : accounts)
        {
            sum = 0;
            for (int& b : banks)
                sum += b;
            if (maxWealth < sum) maxWealth = sum;
        }
        return maxWealth;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> accounts1 = {{1, 5}, {7, 3}, {3, 5}};
        vector<vector<int>> accounts2= {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
        cout << maximumWealth(accounts2) << endl;

        cout << "System ready." << endl;
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}