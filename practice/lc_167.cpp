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
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> indices;

        while (start < end)
        {
            if (target - numbers[end] == numbers[start]) 
            {
                indices = {start + 1, end + 1};
                break;
            }
            else if (target - numbers[end] > numbers[start]) start++;
            else if (target - numbers[end] < numbers[start]) end--;
        }

        return indices;
    }

    void solve()
    {
        // My test case code
        vector<int> numbers = {2, 7, 11, 15};
        // vector<int> numbers = {2, 3, 4};
        // vector<int> numbers = {-1, 0};
        int target = 9;

        for (int x : twoSum(numbers, target)) cout << x << ", ";

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