// 56. Merge Intervals

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
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;

        for (int i = 0; i < intervals.size();)
        {
            int minStart = intervals[i][0];
            int maxEnd = intervals[i][1];
            int j = i;

            while (j < intervals.size() && intervals[j][0] <= maxEnd)
            {
                maxEnd = max(maxEnd, intervals[j][1]);
                j++;
            }

            mergedIntervals.push_back({minStart, maxEnd});
            
            i = j;
        }

        return mergedIntervals;
    }

    void solve()
    {
        // My test case code
        // vector<vector<int>> intervals =
        // {
        //     {1, 3},
        //     {2, 6},
        //     {8, 10},
        //     {15, 18}
        // };

        vector<vector<int>> intervals =
        {
            {1, 3},
            {2, 6},
            {8, 10},
            {9, 11},
            {15, 18},
            {2, 4},
            {16, 17}
        };

        for (vector<int> v : merge(intervals))
        {
            cout << "{" << v[0] << ", " << v[1] << "}" << endl;
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