// 933. Number of Recent Calls

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

class RecentCounter
{
private:
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t)
    {
        while (!q.empty() && q.front() < t - 3000) 
            q.pop();

        q.push(t);

        return q.size();
    }
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    void solve()
    {
        // My test case code
        
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