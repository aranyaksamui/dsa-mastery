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


long long minimumSmokeRequired(vector<int> input)
{
    long long people = input[0];
    long long vanSmoke = input[1];
    long long carSmoke = input[2];

    // Default to van first and calculate the remaining people
    long long vanCount = people / 100;
    long long remPeople = people % 100;

    // Cars for the remaining people and round off to ceil value for extra people
    long long carsForRem = (remPeople + 3) / 4;

    // Option 1 - We take van and cars for the remaining
    long long carAndVanSmoke = (vanCount * vanSmoke) + (carsForRem * carSmoke);

    // Option 2 - We take only vans for all the people
    if (remPeople > 0) vanCount + 1;
    long long onlyVanSmoke = vanCount * vanSmoke;

    // Option 3 - We take only cars for all the people
    long long onlyCarSmoke = ((people + 3) / 4) * carSmoke;

    // Calculate and return the min among cars + van, only van and only cars
    return min(carAndVanSmoke, min(onlyVanSmoke, onlyCarSmoke));
}

int main()
{
    vector<int> input = {105, 50, 10};

    cout << minimumSmokeRequired(input) << endl;
}