/*
    LeetCode: 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
*/

#include <bits/stdc++.h>

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
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        int count = 0;

        int e = 0;
        int sum = 0;
        
        for (; e < k; e++) sum = sum + arr[e];
        
        float avg = (float) sum / (float) k;
        
        if (avg >= (float) threshold) count++;

        int s = 0;
        for (; e < arr.size(); e++)
        {
            sum = arr[e] + sum - arr[s];
            avg = (float) sum / float (k);
            
            if (avg >= (float) threshold) count++;

            cout << "avg: " << avg << endl;
            cout << "count: " << count << endl;
            
            s++;
        }

        return count;
    }

    void solve()
    {
        // My test case code
        vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
        int k = 3;
        int threshold = 5;

        cout << numOfSubarrays(arr, k, threshold) << endl;
        
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