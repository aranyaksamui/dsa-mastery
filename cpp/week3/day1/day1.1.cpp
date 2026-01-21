// Hash maps

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // Declaration (<key type, value type>)
    unordered_map<string, int> mp;

    // Insertion
    mp["Aranyak"] = 29;
    mp["Shounak"] = 04;

    // Access
    cout << mp["Aranyak"] << endl;

    // Update
    mp["Aranyak"] = 11;
    cout << "Updated value: " << mp["Aranyak"] << endl;

    // Check existence
    if (mp.count("Aranyak"))
        cout << "Found Aranyak" << endl;
    else
        cout << "Did not find Aranyak" << endl;

    // Iteration (x is a std::pair)
    for (auto x : mp)
        cout << "Key: " << x.first << ", Value: " << x.second << endl;

    return 0;
}


/*
    Test Results:

    29

    Updated value: 11

    Found Aranyak

    Key: Shounak, Value: 4
    Key: Aranyak, Value: 11


*/