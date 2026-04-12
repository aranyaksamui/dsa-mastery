// 621. Task Scheduler

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
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> taskFrequencies;

        for (char t : tasks) taskFrequencies[t]++;

        priority_queue<int> maxFrequencies;
        for (pair<char, int> p : taskFrequencies) maxFrequencies.push(p.second);

        queue<pair<int, int>> waitingQueue;

        int time = 0;
        while (!maxFrequencies.empty() || !waitingQueue.empty())
        {
            time++;
            if (!maxFrequencies.empty())
            {
                int topFreq = maxFrequencies.top();
                maxFrequencies.pop();
                topFreq--;
    
                if (topFreq > 0)
                {
                    pair<int, int> leftOutFreq;
                    leftOutFreq.first = topFreq;
                    leftOutFreq.second = time + n;
                    waitingQueue.push(leftOutFreq);
                }
            }

            if (!waitingQueue.empty() && waitingQueue.front().second == time)
            {
                maxFrequencies.push(waitingQueue.front().first);
                waitingQueue.pop();
            }
        }

        return time;
    }

    void solve()
    {
        // My test case code
        vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n = 2;

        cout << leastInterval(tasks, n) << endl;

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