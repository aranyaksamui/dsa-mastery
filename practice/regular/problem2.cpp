#include <iostream>
#include <vector>

using namespace std;

vector<int> customFibonacci(int n, int a, int b)
{
    vector<int> dp;

    // Push the first two given numbers
    dp.push_back(5);
    dp.push_back(6);

    // Calculate the fibonacci for the rest of the n numbers and store it inside the dp array
    for (int i = 2; i < 7; i++)
        dp.push_back(dp[i - 1] + dp[i - 2]);
    
    return dp;
}

int main()
{
    int n = 7;
    int a = 5;
    int b = 6;
    for (int x : customFibonacci(n, a, b)) cout << x << " ";
}