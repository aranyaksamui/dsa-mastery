// 54. Spiral Matrix

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
    vector<int> numbers;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int row = 0;
        int col = 0;

        while (matrix[row][col + 1] != -1 && matrix[row + 1][col] != -1)
        {
            if (matrix[row][col + 1] <= matrix[0].size() || matrix[row][col + 1] != -1)
            {
                matrix[row][col + 1] = -1;
                col++;
            }
            // if (matrix)
        }
    }

    void solve()
    {
        // My test case code
        vector<vector<int>> matrix =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        spiralOrder(matrix);

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