// 150. Evaluate Reverse Polish Notation

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
    int evalRPN(vector<string>& tokens)
    {
        stack<int> nums;

        for (string c : tokens)
        {
            if (!nums.empty() && nums.size() >= 2 && c == "+")
            {
                int sum = nums.top();
                nums.pop();
                sum = sum + nums.top();
                nums.pop();
                nums.push(sum);
                cout << "ADD: " << nums.top() << endl;
            }
            else if (!nums.empty() && nums.size() >= 2 && c == "-")
            {
                int dif = nums.top();
                nums.pop();
                dif = nums.top() - dif;
                nums.pop();
                nums.push(dif);
                cout << "DIF: " << nums.top() << endl;
            }
            else if (!nums.empty() && nums.size() >= 2 && c == "*")
            {
                int pro = nums.top();
                nums.pop();
                pro = pro * nums.top();
                nums.pop();
                nums.push(pro);
                cout << "PRO: " << nums.top() << endl;
            }
            else if (!nums.empty() && nums.size() >= 2 && c == "/")
            {
                int quo = nums.top();
                nums.pop();
                quo = nums.top() / quo;
                nums.pop();
                nums.push(quo);
                cout << "QUO: " << nums.top() << endl;
            }
            else
            {
                nums.push(stoi(c));
                cout << c << endl;
            }
        }

        return nums.top();
    }

    void solve()
    {
        // My test case code
        vector<string> s1;
        // s1 = {"2", "1", "+", "3", "*"};
        // cout << evalRPN(s1) << endl;

        // s1 = {"4", "13", "5", "/", "+"};
        // cout << evalRPN(s1) << endl;

        s1 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        cout << evalRPN(s1) << endl;




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