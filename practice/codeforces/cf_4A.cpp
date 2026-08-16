/*
    4A. Watermelon
*/


#include <bits/stdc++.h>

using namespace std;


string can_divide(int n)
{
    if (n > 2 && n % 2 == 0)
        return "YES";
    
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string ans = can_divide(n);

    cout << ans << endl;
}