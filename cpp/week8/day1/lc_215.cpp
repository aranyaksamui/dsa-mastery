// 215. Kth Largest Element in an Array

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
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : nums)
        {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;

        cout << findKthLargest(nums, k) << endl;

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