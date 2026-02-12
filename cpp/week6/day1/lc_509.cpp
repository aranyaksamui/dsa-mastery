// 509. Fibonacci Number

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
    int fib(int n)
    {
        if (n == 1 || n == 0) return n;
        return fib(n - 1) + fib(n - 2);
    }

    void solve()
    {
        // My test case code
        cout << fib(4) << endl;
        cout << fib(3) << endl;
        cout << fib(2) << endl;

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