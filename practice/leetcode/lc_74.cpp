// 74. Search a 2D Matrix

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
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rStart = 0;
        int rEnd = matrix.size() - 1;

        int cStart = 0;
        int cEnd = matrix[0].size() - 1;

        int rowMid = 0;

        while (rStart <= rEnd)
        {
            int rMid = rStart + (rEnd - rStart) / 2;

            if (rMid != matrix.size() - 1 && target >= matrix[rMid][cStart] && target < matrix[rMid + 1][cStart])
            {
                rowMid = rMid;
                if (matrix[rowMid][cStart] == target) return true;
                break;
            }
            else if (rMid == matrix.size() - 1)
            {
                rowMid = rMid;
                if (matrix[rowMid][cStart] == target) return true;
                break;
            }
            else if (target > matrix[rMid][cStart])
                rStart = rMid + 1;
            else if (target < matrix[rMid][cStart])
                rEnd = rMid - 1;
        }

        while(cStart <= cEnd)
        {
            int cMid = cStart + (cEnd - cStart) / 2;

            if (target == matrix[rowMid][cMid])
                return true;
            else if (target < matrix[rowMid][cMid])
                cEnd = cMid - 1;
            else if (target > matrix[rowMid][cMid])
                cStart = cMid + 1;
        }

        return false;
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> matrix =
        {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
        };
        int target = 30;

        // vector<vector<int>> matrix = {{1}};
        // int target = 0;

        // vector<vector<int>> matrix = {{1}, {3}};
        // int target = 1;

        cout << searchMatrix(matrix, target) << endl;

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