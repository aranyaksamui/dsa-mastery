/*
    A keyboard has only lowercase English letters.
    Some keys are broken.

    Given
    • a word
    • the list of broken letters

    determine whether the word can be typed.

    Print:
    YES
    or
    NO

    Example -
    Input:
    computer
    3
    oez
    Output:
    NO
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


void canBeTyped()
{
    // Input - Reading from STDIN
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int n;
    cout << "Enter the no. of broken keys: ";
    cin >> n;

    vector<char> brokenKeys;
    cout << "Enter the broken keys:" << endl;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        brokenKeys.push_back(c);
    }

    cout << endl;

    // Code Start
    set<int> bKeysSet;
    for (int i = 0; i < brokenKeys.size(); i++)
        bKeysSet.insert(brokenKeys[i]);

    for (char ch : str)
    {
        if (bKeysSet.count(ch))
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main()
{
    canBeTyped();

    return 0;
}
