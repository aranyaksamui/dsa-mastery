/*
    Bubble Sort (Ascending)

    Input N numbers.
    Store them in an array.
    Perform bubble sorting on them.
    Output the sorted array.

    Input:
    The first line consists of an integer representing the no. of elements in the array.
    The second line are the sample input elements inside the array random order.

    Output:
    The sorted elements in ascending order.

    Sample Input:
    5
    10 30 21 23 4

    Sample Output:
    4 10 21 23 30
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

    // Program
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j - 1] < arr[j]) continue;

            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }

    // Output
    for (int x : arr) cout << x << " ";

    cout << endl;
    return 0;
}
