/*
    LeetCode: 14. Longest Common Prefix (not yet complete)
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

struct TrieNode
{
    unordered_map<char, TrieNode*> nodes;
    int reps = 0;

    TrieNode() : nodes(), reps(0) {}
};

// Solution Class (Like LeetCode)
class Solution
{
private:
    string longestPrefix = "";
    
public:
    TrieNode* createNode()
    {
        TrieNode* newNode = new TrieNode();
        return newNode;
    }

    void failFastInsert(string& s, TrieNode* t, int idx)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (!t->nodes.count(ch) && idx == 0) 
            {
                t->nodes[ch] = createNode();
                t->reps++;
            }
            else if (t->nodes.count(ch)) t->reps++;
            else return;

            t = t->nodes[ch];
        }
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 1) return strs[0];

        TrieNode* root = new TrieNode();

        int idx = 0;
        for (string& s : strs)
        {
            failFastInsert(s, root, idx);
            idx++;
        }

        string st = strs[0];
        TrieNode* t = root;
        int i = 0;
        while (i < st.size())
        {      
            if (t->reps == strs.size()) longestPrefix.push_back(st[i]);
            else break;

            t = t->nodes[st[i]];
            i++;
        }

        return longestPrefix;
    }

    void solve()
    {
        // My test case code
        vector<string> strs =
        {
            "flower",
            "flow",
            "flight"
        };

        longestCommonPrefix(strs);

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