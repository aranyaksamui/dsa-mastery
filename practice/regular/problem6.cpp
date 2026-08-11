#include <iostream>

using namespace std;

void magicNumber()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int imd = n;
    while (imd / 10 != 0)
    {
        int temp = imd;
        int squaredSum = 0;
        while (temp > 0)
        {
            int rem = temp % 10;
            squaredSum += (rem * rem);
            temp = temp / 10;
        }

        imd = squaredSum;
    }

    if (imd == 1) cout << "MAGIC" << endl;
    else cout << "NOT MAGIC" << endl;
}

int main()
{
    magicNumber();

    return 0;
}
