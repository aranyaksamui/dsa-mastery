/*
    Codeforces: 158A. Next Round
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

int participants(int k, vector<int> contestants)
{
    if (k == contestants.size() - 1 && contestants[k] > 0) return k;

    if (k < contestants.size() - 1 && contestants[k] > 0)
    {
        for (; k < contestants.size() && contestants[k] == contestants[k + 1]; k++);
        return k;
    }
        
    if (k < contestants.size() && contestants[k] <= 0)
        for (; k > 0 && contestants[k] <= 0; k--);

    return k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> contestants(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        int c;
        cin >> c;
        contestants[i] = c;
    }

    int ans = participants(k, contestants);

    cout << ans << endl;
}