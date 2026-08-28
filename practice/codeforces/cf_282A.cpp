/*
    Codeforces: 282A. Bit++
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

int calcBit(vector<string> ops)
{
    int X = 0;

    for (string op : ops)
    {
        if (op[1] == '+')
            X++;
        else
            X--;
    }

    return X;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    vector<string> operations;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        operations.push_back(op);
    }

    int ans = calcBit(operations);

    cout << ans << endl;
}