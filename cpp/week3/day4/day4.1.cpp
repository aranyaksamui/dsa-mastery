// stringstream

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