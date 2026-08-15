/*
    Smart Parking Allocation

    Problem Statement:
        A shopping mall has a parking area where vehicles enter and leave throughout the day.
        For every vehicle, the parking system records its entry time and exit time in minutes from midnight.
        The management wants to determine the minimum number of parking slots required so that every vehicle can be
        accommodated without making any vehicle wait.
        If one vehicle leaves at exactly the same time another vehicle enters, the parking slot becomes immediately
        available.
        Given the entry and exit times of all vehicles, determine the maximum number of vehicles present in the parking
        area at the same time.

    Input Format
        The first line contains an integer N, representing the number of vehicles.
        The next N lines contain two space-separated integers:
        entryTime exitTime

    Output Format
        Print a single integer representing the minimum number of parking slots required.

    Constraints
        •1 <= N <= 2 * 10^5
        •0 <= entryTime < exitTime <= 1440

    Sample Input
        5
        100 300
        200 400
        250 350
        300 500
        600 800

    Sample Output
        3
*/


#include <bits/stdc++.h>

using namespace std;


#define MAX 1440

int minVehiclesReq(vector<int>& intervals)
{
    int maxCars = 0;
    int prefixSum = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        prefixSum += intervals[i];
        maxCars = max(maxCars, prefixSum);
    }

    return maxCars;
}

int main()
{
    // Input
    int n;
    cin >> n;

    vector<int> intervals(MAX, 0);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> interval;
        cin >> interval.first >> interval.second;
        intervals[interval.first]++;
        intervals[interval.second]--;
    }

    // Program
    int minVehicles = minVehiclesReq(intervals);

    // Output
    cout << minVehicles << endl;

    cout << endl;
    return 0;
}
