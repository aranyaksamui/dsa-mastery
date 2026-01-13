// Reverse an array using Two Pointers in-place

#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int>& arr)
{
    // Setup the two pointers
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        // Swap the elements (can also be done using - std::swap(arr[start], arr[end]))
        int n = arr[start];
        arr[start] = arr[end];
        arr[end] = n;
        // Move pointers inwards
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    vector<int> a = arr;
    vector<int>& b = arr;
    cout << "Original Array: " << endl;
    for (int x : arr) cout << x << " ";

    reverseArray(arr);
    cout << endl << "Reversed Array: " << endl;
    for (int x : arr) cout << x << " ";


    return 0;
}

/*
    Test Results:

    Original Array: 
    10 20 30 40 50 60

    Reversed Array: 
    60 50 40 30 20 10 
*/