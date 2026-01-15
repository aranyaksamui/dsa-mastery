// 125. Valid Palindrome

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
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
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (!isalnum(s[start]) && !isalnum(s[end]))
        {
            if (start >= end) return true;
            start++;
            end--;
        }
        
        bool isPalindrome = false;
        while (start <= end)
        {
            if (!isalnum(s[start]) && !isalnum(s[end])) { start++; end--; continue; }
            if (!isalnum(s[start])) { start++; continue; }
            if (!isalnum(s[end])) { end--; continue; }

            if (tolower(s[start]) == tolower(s[end]))
                isPalindrome = true;
            else 
            { 
                isPalindrome = false; 
                return isPalindrome; 
            }

            start++;
            end--;
        }
        return isPalindrome;
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