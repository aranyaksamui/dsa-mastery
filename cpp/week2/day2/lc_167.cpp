// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
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
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;

        vector<int> indices = {0, 0};
        while (start < end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
            {
                indices[0] = start + 1;
                indices[1] = end + 1;
                return indices;
            }
            else if (sum > target) end--;
            else if (sum < target) start++;
        }
        return indices;
    }

    void solve()
    {
        // My test case code
        vector<int> numbers = {-1, -1, 1, 1, 1};
        int target = -2;

        for (int x : twoSum(numbers, target)) cout << x << " ";

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