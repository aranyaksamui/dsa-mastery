#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Declaring a queue
    queue<int> q;

    // Inserting values at the back of the queue
    for (int i = 0; i < 10; i++) q.push(i * 10);

    cout << "Front element of the queue: " << q.front() << endl;
    cout << "Back element of the queue: " << q.back() << endl;

    // Removing elements from the from of the front of the queue
    q.pop();
    q.pop();

    cout << "Front element of the queue: " << q.front() << endl;
    cout << "Back element of the queue: " << q.back() << endl;

    return 0;
}

/*
    Test results:

    Front element of the queue: 0
    Back element of the queue: 90
    
    Front element of the queue: 20
    Back element of the queue: 90
*/