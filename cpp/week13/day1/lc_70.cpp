// 70. Climbing Stairs

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
    vector<int> memo;
public:
    int climbStairsHelper(int n)
    {
        if (memo[n] > 0) return memo[n];
        else if (n == 1)
        {
            memo[n] = 1;
            return memo[n];
        }
        else if (n == 2)
        {
            memo[n] = 2;
            return memo[n];
        }

        memo[n] = climbStairsHelper(n - 2) + climbStairsHelper(n - 1);
        return memo[n];
    }

    int climbStairs(int n)
    {
        if (n <= 1) return n;

        memo.resize(n + 1, 0);

        return climbStairsHelper(n);
    }

    void solve()
    {
        // My test case code
        // int n = 3;

        int n = 7;
    
        cout << climbStairs(n) << endl;
        
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