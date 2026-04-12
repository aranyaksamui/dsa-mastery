// 347. Top K Frequent Elements

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
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> numCounts;

        for (int n : nums) numCounts[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> numFreqSorted;

        for (pair<int, int> p : numCounts)
        {
            pair<int, int> tempPair;
            tempPair.first = p.second;
            tempPair.second = p.first;

            numFreqSorted.push(tempPair);
            if (numFreqSorted.size() > k) numFreqSorted.pop();
        }

        vector<int> maxFrequencyNums;
        while (!numFreqSorted.empty())
        {
            maxFrequencyNums.push_back(numFreqSorted.top().second);
            numFreqSorted.pop();
        }

        return maxFrequencyNums;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;

        for (int x : topKFrequent(nums, k)) cout << x << " ";

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