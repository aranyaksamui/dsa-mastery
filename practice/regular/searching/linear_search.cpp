/*
    Linear Search (Single Element)

    Given an array of numbers.
    Find the target element.
    Output the index of the target element.
    If the target element does not exist in the array, output -1.

    Input:
    The first line is the no. of elements of the array.
    The second line is the elements of the array.
    The Third line is the target element.

    Output:
    The index of the target element.

    Sample Input:
    5
    10 20 30 40 50
    30

    Sample Output:
    Target found at: 2
*/


#include <iostream>
#include <vector>

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
    int idx = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            idx = i;
            break;
        }
    }

    // Output
    if (idx != -1) cout << "Target found at: " << idx << endl;
    else cout << "Target is not present in array" << endl;


    cout << endl;
    return 0;
}
