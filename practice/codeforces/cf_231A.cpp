/*
    Codeforces: 231A. Team
*/


#include <bits/stdc++.h>

using namespace std;


int no_of_problems(vector<vector<int>>& problems)
{
    int total_problems = 0;

    for (int i = 0; i < problems.size(); i++)
    {
        int curr_sol = 0;
        for (int j = 0; j < problems[i].size(); j++)
            if (problems[i][j] != 0) curr_sol++;

        if (curr_sol > 1) total_problems++;
    }

    return total_problems;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int n;
    cin >> n;

    vector<vector<int>> problems(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            int a;
            cin >> a;
            problems[i].push_back(a);
        }
    }

    // Program
    int ans = no_of_problems(problems);

    // Output
    cout << ans << endl;

    return 0;
}