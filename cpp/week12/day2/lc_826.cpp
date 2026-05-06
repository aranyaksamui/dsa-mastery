// 826. Most Profit Assigning Work

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
    void sortArrays(vector<pair<int, int>>& jobSpecs, vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        int n = difficulty.size();
        
        for (int i = 0; i < n; i++)
        jobSpecs.push_back({difficulty[i], profit[i]});
        
        sort(jobSpecs.begin(), jobSpecs.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, jobSpecs[i].second);
            jobSpecs[i].second = maxProfit;
        }
    }

    int maximizeProfit(int n, vector<pair<int, int>>& jobSpecs, vector<int>& worker)
    {
        int totalProfit = 0;
        int jobIndex = 0;

        for (int j = 0; j < worker.size(); j++)
        {
            int ability = worker[j];

            while (jobIndex < jobSpecs.size() && ability >= jobSpecs[jobIndex].first)
                jobIndex++;

            if (jobIndex > 0) totalProfit += jobSpecs[jobIndex - 1].second;
        }

        return totalProfit;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int, int>> jobSpecs;

        sortArrays(jobSpecs, difficulty, profit, worker);

        return maximizeProfit(difficulty.size(), jobSpecs, worker);;
    }

    void solve()
    {
        // My test case code
        // vector<int> difficulty = {2, 4, 6, 8, 10};
        // vector<int> profit = {10, 20, 30, 40, 50};
        // vector<int> worker = {4, 5, 6, 7};

        vector<int> difficulty = {68, 35, 52, 47, 86};
        vector<int> profit = {67, 17, 1, 81, 3};
        vector<int> worker = {92, 10, 85, 84, 82};

        cout << maxProfitAssignment(difficulty, profit, worker) << endl;

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