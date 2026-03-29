// 51. N-Queens

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
    int N;
    vector<vector<string>> boards;
    unordered_set<int> cols, negDiag, posDiag;

public:
    void nQueenHelper(int row, vector<string>& currentBoard)
    {
        if (row == N)
        {
            boards.push_back(currentBoard);
            return;
        }

        for (int col = 0; col < N; col++)
        {
            if (cols.count(col) || negDiag.count(row - col) || posDiag.count(row + col)) continue;

            currentBoard[row][col] =  'Q';

            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);

            nQueenHelper(row + 1, currentBoard);

            currentBoard[row][col] = '.';

            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
        }
    }
    
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;

        vector<string> currentBoard(N, string(N, '.'));

        nQueenHelper(0, currentBoard);

        return boards;
    }

    void solve()
    {
        // My test case code
        int n = 4;
        for (vector<string> v : solveNQueens(n))
        {
            for (string s : v) cout << s << endl;
            cout << endl;
        }
        
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