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
    vector<int> sortedNums;

public:
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        vector<int> tempArr;
        int left = start;
        int right = mid + 1;

        while (left <= mid && right <= end)
        {
            if (nums[left] <= nums[right])
                tempArr.push_back(nums[left++]);
            else if (nums[left] > nums[right])
                tempArr.push_back(nums[right++]);
        }

        while (left <= mid) tempArr.push_back(nums[left++]);
        while (right <= end) tempArr.push_back(nums[right++]);

        for (int i = start; i <= end; i++)
            nums[i] = tempArr[i - start];
    }

    void sortArrayHelper(vector<int>& nums, int start, int end)
    {
        if (start >= end) return;
        
        int mid = start + (end - start) / 2;

        sortArrayHelper(nums, start, mid);
        sortArrayHelper(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        sortArrayHelper(nums, start, end);
        return nums;
    }

    void solve()
    {
        // My test case code
        vector<int> nums = {5, 2, 3, 1};

        for (int x : sortArray(nums)) cout << x << " ";

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