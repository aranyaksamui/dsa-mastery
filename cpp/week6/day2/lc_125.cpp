// 125. Valid Palindrome (recursive approach)

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
    bool isPalHelper(string& s, int start, int end)
    {
        if (start >= end) return true;
        
        if (!isalnum(s[start]) && !isalnum(s[end])) return isPalHelper(s, ++start, --end);
        
        if (!isalnum(s[start])) return isPalHelper(s, ++start, end);
        if (!isalnum(s[end])) return isPalHelper(s, start, --end);
        
        if (tolower(s[start]) == tolower(s[end])) return isPalHelper(s, ++start, --end);
        else return false;
    }

    bool isPalindrome(string s)
    {
        if (s.size() == 0) return true;

        int start = 0;
        int end = s.size() - 1;

        return isPalHelper(s, start, end);
    }

    void solve()
    {
        // My test case code
        string s = "A man, a plan, a canal: Panama";
        cout << isPalindrome(s) << endl;

        s = "race a car";
        cout << isPalindrome(s) << endl;

        s = " ";
        cout << isPalindrome(s) << endl;


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