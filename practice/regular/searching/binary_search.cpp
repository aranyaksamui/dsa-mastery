/*
    Binary Search

    Given an array of numbers.
    Find the target element.
    Output the index of the target element.
    If the target element does not exist in the array, output -1.

    Input:
    The first line is the no. of elements in the array.
    The second line is the elements of the array.
    The third line is the target element.

    Output:
    The sorted array.
    The index of the target element.

    Sample Input:
    5
    12 23 24 11 56
    11

    Sample Output:
    11 12 23 24 56
    Target found at: 0
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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

    int target;
    cin >> target;

    // Program
    sort(arr.begin(), arr.end());

    int l = 0;
    int r = arr.size() - 1;
    int idx = -1;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (arr[mid] == target)
        {
            idx = mid;
            break;
        }
        else if (target < arr[mid]) r = mid - 1;
        else if (target > arr[mid]) l = mid + 1;
    }

    // Output
    for (int x : arr) cout << x << " ";
    cout << endl;

    if (idx != -1) cout << "Target found at: " << idx << endl;
    else cout << "Target is not present in array" << endl;

    return 0;
}
