// 295. Find Median from Data Stream

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

class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> largeNums;
    priority_queue<int> smallNums;
public:
    MedianFinder() {}

    void addNum(int num)
    {
        smallNums.push(num);

        largeNums.push(smallNums.top());
        smallNums.pop();

        if (largeNums.size() > smallNums.size()) 
        {
            smallNums.push(largeNums.top());
            largeNums.pop();
        }
    }

    double findMedian()
    {
        if (smallNums.size() > largeNums.size()) return (double) smallNums.top();
        else return ((double) largeNums.top() + (double) smallNums.top()) / 2;
    }
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    void solve()
    {
        // My test case code
        MedianFinder* medianFinder = new MedianFinder();

        medianFinder->addNum(1);
        medianFinder->addNum(2);
        cout << medianFinder->findMedian() << endl;
        medianFinder->addNum(3);
        cout << medianFinder->findMedian() << endl;


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