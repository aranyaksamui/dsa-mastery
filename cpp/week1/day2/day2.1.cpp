#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declaring an empty vector
    vector<int> v;
    
    // Adding elements to the vector and watching it resizing
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i * 10);
        cout << "At " << i << " size is: " << v.size() << " and capacity is: " << v.capacity() << endl;
        cout << "Memory of the first index of the vector v: " << &v[0] << endl;
    }

    // Accessing an element
    cout << v[4] << endl;

    // Deleting an element from the end
    v.pop_back();
    cout << "Currently the size is: " << v.size() << " and capacity is: " << v.capacity() << endl;

    return 0;
}

/*
    Test results:

    At 0 size is: 1 and capacity is: 1
    Memory of the first index of the vector v: 0x1119ea8
    At 1 size is: 2 and capacity is: 2
    Memory of the first index of the vector v: 0x1119eb8
    At 2 size is: 3 and capacity is: 4
    Memory of the first index of the vector v: 0x1119ec8
    At 3 size is: 4 and capacity is: 4
    Memory of the first index of the vector v: 0x1119ec8
    At 4 size is: 5 and capacity is: 8
    Memory of the first index of the vector v: 0x1119f10
    At 5 size is: 6 and capacity is: 8
    Memory of the first index of the vector v: 0x1119f10
    At 6 size is: 7 and capacity is: 8
    Memory of the first index of the vector v: 0x1119f10
    At 7 size is: 8 and capacity is: 8
    Memory of the first index of the vector v: 0x1119f10
    At 8 size is: 9 and capacity is: 16
    Memory of the first index of the vector v: 0x1119f38
    At 9 size is: 10 and capacity is: 16
    Memory of the first index of the vector v: 0x1119f38

    40

    Currently the size is: 9 and capacity is: 16
*/