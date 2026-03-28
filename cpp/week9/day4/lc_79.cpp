// 79. Word Search

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
    bool wordSearchHelper(vector<vector<char>>& board, string& word, int row, int col, int wIndex)
    {
        if (wIndex == word.size()) return true;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || word[wIndex] != board[row][col])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';
        
        bool found = wordSearchHelper(board, word, row - 1, col, wIndex + 1) || 
                     wordSearchHelper(board, word, row + 1, col, wIndex + 1) ||
                     wordSearchHelper(board, word, row, col - 1, wIndex + 1) ||
                     wordSearchHelper(board, word, row, col + 1, wIndex + 1);
        
        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string& word)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                if (board[row][col] != word[0]) continue;

                if (wordSearchHelper(board, word, row, col, 0)) return true;
            }
        }

        return false;
    }

    void solve()
    {
        // My test case code
        // vector<vector<char>> board =
        // {
        //     {'A', 'B', 'C', 'E'},
        //     {'S', 'F', 'C', 'S'},
        //     {'A', 'D', 'E', 'E'}
        // };

        // string word = "ABCCED";

        vector<vector<char>> board =
        {
            {'A', 'B'},
            {'C', 'D'},
        };

        string word = "ABCD";
        // string word = "SEE";

        cout << exist(board, word) << endl;
        
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