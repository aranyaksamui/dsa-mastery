// 349. Intersection of Two Arrays

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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> s;
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++)
            s.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.count(nums2[i]))
            {
                result.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }

        return result;
    }

    void solve()
    {
        // My test case code
        // vector<int> nums1 = {1, 2, 2, 1};
        // vector<int> nums2 = {2, 2};

        // for (int x : intersection(nums1, nums2)) cout << x << " ";

        vector<int> nums1 = {4, 9, 5};
        vector<int> nums2 = {9, 4, 9, 8, 4};

        for (int x : intersection(nums1, nums2)) cout << x << " ";

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