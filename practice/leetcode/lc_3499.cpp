/*
    LeetCode: 3499. Maximize Active Section with Trade I
*/

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
    int maxActiveSectionsAfterTrade(string s)
    {
        int totalOnes = 0;
        vector<int> zeroBlocks;
        int currentZeros = 0;

        for (char c : s)
        {
            if (c == '1')
            {
                totalOnes++;
                if (currentZeros > 0)
                {
                    zeroBlocks.push_back(currentZeros);
                    currentZeros = 0;
                }
            }
            else currentZeros++;
        }

        if (totalOnes == 0) return 0;
        if (totalOnes == s.size()) return totalOnes;

        if (currentZeros > 0) zeroBlocks.push_back(currentZeros);

        if (zeroBlocks.size() < 2) return totalOnes;

        int maxZeroPair = 0;
        for (size_t i = 0; i < zeroBlocks.size() - 1; i++)
            maxZeroPair = max(maxZeroPair, zeroBlocks[i] + zeroBlocks[i + 1]);        

        return maxZeroPair + totalOnes;
    }

    void solve()
    {
        // My test case code
        string s = "1000100";

        maxActiveSectionsAfterTrade(s);
        
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