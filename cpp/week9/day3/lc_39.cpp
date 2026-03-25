// 39. Combination Sum

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
    vector<vector<int>> combinations;
public:
    void combiSumHelper(vector<int>& candidates, int target, vector<int>& currentCombi, int i)
    {
        if (target == 0)
        {
            combinations.push_back(currentCombi);
            return;
        }
        
        if (i >= candidates.size() && target > 0) return;
        
        for (; i < candidates.size(); i++)
        {
            int nextTarget = target - candidates[i];
            if (nextTarget < 0) continue;
            
            currentCombi.push_back(candidates[i]);
            combiSumHelper(candidates, nextTarget, currentCombi, i);
            currentCombi.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> currentCombi;
        int i = 0;

        combiSumHelper(candidates, target, currentCombi, i);

        return combinations;
    }

    void solve()
    {
        // My test case code
        vector<int> candidates = {2, 3, 6, 7};
        int target = 7;

        // vector<int> candidates = {8, 7, 4, 3};
        // int target = 11;

        for (vector<int>& v : combinationSum(candidates, target))
        {
            for (int x : v) cout << x << " ";
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