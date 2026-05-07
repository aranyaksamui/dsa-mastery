// 435. Non-overlapping Intervals

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
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        int lastEndTime = intervals[0][1];
        int validIntervals = 1;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= lastEndTime)
            {
                validIntervals++;
                lastEndTime = intervals[i][1];
            }
        }

        return n - validIntervals;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> intervals = 
        {
            {1, 2}, 
            {2, 3}, 
            {3, 4}, 
            {1, 3}
        };

        cout << eraseOverlapIntervals(intervals) << endl;
        
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