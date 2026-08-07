/*
    LeetCode: 1081. Smallest Subsequence of Distinct Characters
*/

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
    string smallestSubsequence(string s)
    {
        unordered_map<char, int> charCount;
        for (int i = 0; i < s.length(); i++) charCount[s[i]]++;

        set<char> visited;
        string mStack;

        for (int i = 0; i < s.length(); i++)
        {
            if (!visited.count(s[i]))
            {
                while (mStack.size() > 0 && mStack[mStack.size() - 1] > s[i])
                {
                    char top = mStack[mStack.size() - 1];
                    if (charCount[top] > 0)
                    {
                        mStack.pop_back();
                        visited.erase(top);
                    }
                    else break;
                }
                mStack.push_back(s[i]);
                visited.insert(s[i]);
            }

            charCount[s[i]]--;
        }

        return mStack;
    }

    void solve()
    {
        // My test case code
        // string s = "cbacdcbc";
        string s = "thequickbrownfoxjumpsoverthelazydog";

        cout << smallestSubsequence(s) << endl;

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