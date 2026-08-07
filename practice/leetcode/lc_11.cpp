// 11. Container With Most Water
// My Time Complexity: O(N)

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
    int maxArea(vector<int>& height)
    {
        int maximumArea = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start <= end)
        {
            maximumArea = max(maximumArea, min(height[start], height[end]) * (end - start));

            if (height[start] < height[end])
                start++;
            else
                end--;
        }

        return maximumArea;
    }

    void solve()
    {
        // My test case code
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        
        cout << maxArea(height) << endl;

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