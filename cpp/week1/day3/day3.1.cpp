// Value vs. Reference

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    cout << arr[0] << " address: " << &arr[0] << endl;

    cout << "Loop by value" << endl;

    // Loop by value (data "x" is a copy of the original data in a specific index in arr in a specific iteration)
    // Note: x is not the entire vector but a variable in the stack that takes data from the heap (vector) in a specific iteration and then overwrites the old data in the next iteration
    for (int x : arr)
    {
        cout << x << " address: " << &x << "    ";
        // Trying to update the data
        x = x + 5;
        cout << x << " address: " << &x << endl; 
    }
    cout << arr[0] << " address: " << &arr[0] << endl;

    cout << "Loop by reference" << endl;

    // Loop by reference (x is pointing to the actual data in arr vector)
    for (int& x : arr)
    {
        cout << x << " address: " << &x << "    ";
        // Trying to update the data
        x = x + 5;
        cout << x << " address: " << &x << endl;        
    }
    // Value updated
    cout << arr[0] << " address: " << &arr[0] << endl;

    return 0;
}

/*
    Test results:

    10 address: 0x7a9ea8

    Loop by value
    10 address: 0x61fee0    15 address: 0x61fee0
    20 address: 0x61fee0    25 address: 0x61fee0
    30 address: 0x61fee0    35 address: 0x61fee0
    40 address: 0x61fee0    45 address: 0x61fee0
    50 address: 0x61fee0    55 address: 0x61fee0
    60 address: 0x61fee0    65 address: 0x61fee0
    10 address: 0x7a9ea8

    Loop by reference
    10 address: 0x7a9ea8    15 address: 0x7a9ea8
    20 address: 0x7a9eac    25 address: 0x7a9eac
    30 address: 0x7a9eb0    35 address: 0x7a9eb0
    40 address: 0x7a9eb4    45 address: 0x7a9eb4
    50 address: 0x7a9eb8    55 address: 0x7a9eb8
    60 address: 0x7a9ebc    65 address: 0x7a9ebc

    15 address: 0x7a9ea8
*/