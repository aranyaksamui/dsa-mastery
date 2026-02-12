// 231. Power of Two

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
    bool isPowerOfTwo(int n)
    {
        if (n == 1) return true;
        else if (n == 0) return false;

        int factor = n / 2;
        int reminder = n % 2;
        
        if (factor == 1 && reminder == 0) return true;
        if (n % 2 == 0) return isPowerOfTwo(factor);
        else return false;
    }

    void solve()
    {
        // My test case code
        cout << isPowerOfTwo(16) << endl;
        cout << isPowerOfTwo(3) << endl;

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