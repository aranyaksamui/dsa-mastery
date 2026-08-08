#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<pair<char, int>> charCounts(string str)
{
    unordered_map<char, int> hashMap;
    for (int i = 0; i < str.size(); i++)
        hashMap[str[i]]++;
    
    vector<pair<char, int>> result;
    for (auto p : hashMap)
        result.push_back(p);

    return result;
}

int main()
{
    string str = "programming";
    for (pair<char, int> p : charCounts(str)) cout << p.first << " " << p.second << endl;
}