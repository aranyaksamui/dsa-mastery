// Pair & Auto

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // Creating a pair
    pair<int, string> p1 = {29, "Aranyak"};
    cout << p1.first << " " << p1.second << endl << endl;

    // Creating a vector of pairs
    vector<pair<int, string>> vp1 = {p1};
    vp1.push_back({14, "Sagnik"});
    vp1.push_back({06, "Rohit"});
    vp1.push_back({06, "Rahul"});

    // Sorting the vector of pairs (by default sorts a pair using it's first but if first is equal it sorts using second)
    sort(vp1.begin(), vp1.end());

    // Looping through the sorted vector
    for (auto& x : vp1)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}