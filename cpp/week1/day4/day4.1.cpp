// Sorting & The Algorithm Library

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // Sorting the array (ascending order)
    vector<int> v1 = {5, 2, 9, 1, 5, 6};
    sort(v1.begin(), v1.end());

    cout << "Sorted array (ascending order): ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    // Sorting the array (descending order)
    vector<int> v2 = {5, 2, 9, 1, 5, 6};
    sort(v2.begin(), v2.end(), greater<int>());

    cout << "Sorted array (descending order): ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    // Reverse the array in place
    vector<int> v3 = {50, 22, 94, 15, 3, 6};
    reverse(v3.begin(), v3.end());

    cout << "Reversed array: ";
    for (int x : v3) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
    Test results:
    
    Sorted array (ascending order): 1 2 5 5 6 9 
    Sorted array (descending order): 9 6 5 5 2 1 
    Reversed array: 6 3 15 94 22 50 
*/