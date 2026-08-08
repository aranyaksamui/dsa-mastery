#include <iostream>
#include <string>

using namespace std;


int charCount(string str, char c)
{
    int chCount = 0;

    for (int i = 0; i < str.size(); i++)
        if (str[i] == c) chCount++;

    return chCount;
}

int main()
{
    string str = "programming";
    char c = 'g';
    cout << charCount(str, c) << endl;
}
