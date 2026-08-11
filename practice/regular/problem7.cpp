#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void longestStableTemperature()
{
    int n;
    cout << "Enter the no. of temperature readings: ";
    cin >> n;

    vector<int> tmp;
    cout << "Enter the temperatures:" << endl;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tmp.push_back(t);
    }

    vector<int> preDiff(n + 1, 0);
    int maxRange = 0;
    int minRangeIdx = 0;
    int maxRangeIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if ((tmp[i] - tmp[i - 1]) > 2)
        {
            minRangeIdx = i;
            continue;
        }

        preDiff[i] = preDiff[i - 1] + (tmp[i] - tmp[i - 1]);

        if (preDiff[i] > maxRange)
        {
            maxRange = preDiff[i];
            maxRangeIdx = i;
        }
    }

    vector<int> result;
    for (int j = minRangeIdx; j <= maxRangeIdx; j++)
        result.push_back(tmp[j]);

    // DEBUG
    for (int x : preDiff) cout << x << " ";
    cout << endl;
    cout << minRangeIdx << endl;
    cout << maxRangeIdx << endl;
    cout << preDiff[maxRangeIdx] << endl;
    for (int x : result) cout << x << " ";
    cout << endl;
    // DEBUG
}

int main()
{
    longestStableTemperature();

    return 0;
}
