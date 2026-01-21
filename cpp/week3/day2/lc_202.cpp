#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>

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
    bool isHappy(int n)
    {
        unordered_set<int> s;

        while (n != 1)
        {
            int temp = n;
            int sum = 0;
            while (temp != 0)
            {
                int rem = temp % 10;
                sum = sum + (rem * rem);
                temp = temp / 10;
            }
            if (s.count(sum)) return false;
            else s.insert(sum);
            n = sum;
        }
        if (n == 1) return true;
        else return false;
    }

    void solve()
    {
        // My test case code
        
        cout << isHappy(19) << endl;
        cout << isHappy(2) << endl;
        
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