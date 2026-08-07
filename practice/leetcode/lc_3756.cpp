/*
    LeetCode: 3756. Concatenate Non-Zero Digits and Multiply by Sum II
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
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries)
    {
        int m = s.size();
        long long MOD = 1e9 + 7;
        
        vector<long long> pow10(m + 1, 1);
        vector<long long> prefixSum(m + 1, 0);
        vector<int> prefixCount(m + 1, 0);
        vector<long long> prefixVal(m + 1, 0);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int j = 0; j < m; j++)
        {
            int num = s[j] - '0';

            prefixSum[j + 1] = prefixSum[j];
            prefixCount[j + 1] = prefixCount[j];
            prefixVal[j + 1] = prefixVal[j];

            if (num != 0)
            {
                prefixSum[j + 1] += num;
                prefixCount[j + 1]++;
                prefixVal[j + 1] = (prefixVal[j] * 10 + num) % MOD;
            }
        }

        vector<int> ans;

        for (const vector<int>& q : queries)
        {
            int l = q[0];
            int r = q[1];

            long long sum = prefixSum[r + 1] - prefixSum[l];
            
            int count = prefixCount[r + 1] - prefixCount[l];

            long long leftPart = (prefixVal[l] * pow10[count]) % MOD;

            long long x = (prefixVal[r + 1] - leftPart + MOD) % MOD;

            long long answer = (x * sum) % MOD;
            ans.push_back(answer);
        }

        return ans;
    }

    void solve()
    {
        // My test case code
        string s = "10203004";
        vector<vector<int>> queries = 
        {
            {0, 7},
            {1, 3},
            {4, 6}
        };

        for (int x : sumAndMultiply(s, queries)) cout << x << " ";
        
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