/*
    You are given an array of N positive integers and an integer K.
    A valid subarray is a contiguous subarray whose sum is at most K.
    For every valid subarray, calculate its GCD Score:
        GCD Score = GCD(subarray) * length(subarray) where:
            1. GCD(subarray) is the greatest common divisor of all elements in the subarray.
            2. length(subarray) is the number of elements is the subarray.
    Your task is to find the maximum GCD Score among all valid subarrays having at least 2 elements.
    If no valid subarray contains at least 2 elements, return 0.

    Important:
        The answer can be larger than a 32-bit integer, so use a 64-bit integer for the result.

    Input Format:
        The input contains:
            N
            A1, A2, A3 ... AN
            K
        Where:
            1. First line contains integer N.
            2. Second line contains N positive integers.
            3. Third line contains integer K.

    Output Format:
        Print a single integer representing the maximum GCD Score.
        If there is no valid subarray of length at least 2, print:
            0

    Sample Input:
        6
        6 12 18 5 10 15
        40

    Sample Output:
        18
*/


#include <bits/stdc++.h>

using namespace std;

// Returns the GCD of two numbers
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

long long maxGCDScore(vector<int>& arr, int n, long long k)
{
    long long maxScore = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        long long currentSum = arr[i];
        long long currentGCD = arr[i];

        for (int j = i + 1; j < arr.size(); j++)
        {
            currentSum += arr[j];

            if (currentSum > k)
                break;

            currentGCD = gcd(currentGCD, arr[j]);

            long long currentLen = (j - i) + 1;
            long long currentScore = currentGCD * currentLen;

            maxScore = max(maxScore, currentScore);
        }
    }

    return maxScore;
}

int main()
{
    // Input
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int k;
    cin >> k;

    // Program
    long long result = maxGCDScore(arr, n, k);

    // Output
    cout << result << endl;

    cout << endl;
    return 0;
}
