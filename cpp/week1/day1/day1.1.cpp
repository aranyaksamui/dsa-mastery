// Big O and Complexity

#include <iostream>
#include <vector>

using namespace std;

// Constant time O(1) example
int getItemByIndex(vector<int>& arr, int index)
{
    return arr[index];
}

// Linear time O(N) example
int getSumOfArrayElements(vector<int>& arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

// Quadratic time O(N^2) example
void getPairsInArray(vector<int>& arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};

    cout << getItemByIndex(arr, 3) << endl;

    cout << getSumOfArrayElements(arr) << endl;

    getPairsInArray(arr);

    return 0;
}