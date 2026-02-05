// 682. Baseball Game

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
    int calPoints(vector<string>& operations)
    {
        stack<int> points;

        for (string c : operations)
        {
            char ch = c[0];
            switch (ch)
            {
            case '+':
                if (!points.empty() && points.size() >= 2)
                {
                    int temp = points.top();
                    points.pop();
                    int sum = temp + points.top();
                    points.push(temp);
                    points.push(sum);
                }
                break;
            case 'D':
                if (!points.empty()) points.push(points.top() * 2);
                break;
            case 'C':
                if (!points.empty()) points.pop();
                break;
            default:
                points.push(stoi(c));
                break;
            }
        }

        int totalPoints = 0;
        while (!points.empty())
        {
            totalPoints += points.top();
            points.pop();
        }

        return totalPoints;
    }

    void solve()
    {
        // My test case code
        vector<string> ops1 = {"5", "2", "C", "D", "+"};
        cout << calPoints(ops1) << endl;
         
        vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
        cout << calPoints(ops2) << endl; 

        vector<string> ops3 = {"1", "C"};
        cout << calPoints(ops3) << endl; 
        
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