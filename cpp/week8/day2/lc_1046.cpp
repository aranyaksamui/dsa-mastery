// 1046. Last Stone Weight

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
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> sortedStones;

        for (int stone : stones) sortedStones.push(stone);

        while (sortedStones.size() > 1)
        {
            int top0 = 0, top1 = 0;
            top0 = sortedStones.top();
            sortedStones.pop();
            top1 = sortedStones.top();
            sortedStones.pop();
            
            if (top0 != top1) sortedStones.push(top0 - top1);
        }

        if (sortedStones.size() == 1) return sortedStones.top();
        return 0;
    }

    void solve()
    {
        // My test case code
        vector<int> stones = {2, 7, 4, 1, 8, 1};

        cout << lastStoneWeight(stones) << endl;

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