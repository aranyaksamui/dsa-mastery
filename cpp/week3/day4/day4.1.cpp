/*
    WEEK 3: Hashing & The Magic of O(1)
    DAY 4: One-to-One Mappings (Bijection)

    std::stringstream
*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string s = "The lazy fox jumps over the fence!";
    stringstream ss(s);

    string word;

    while (ss >> word)
    {
        cout << word << endl;
    }

    return 0;
}