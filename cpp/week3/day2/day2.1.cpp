#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;

    // Insert
    s.insert(10);
    for (int x : s) cout << x << " ";
    s.insert(10); // Does nothing (10 already exists)
    for (int x : s) cout << x << " ";

    // Check existence
    if (s.count(10))
        cout << "Found item" << endl;

    // Remove element
    s.erase(10);

    return 0;
}