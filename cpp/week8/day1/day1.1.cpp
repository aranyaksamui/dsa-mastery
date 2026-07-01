/*
    WEEK 8: Heaps & Priority Queues
    DAY 1: The Binary Heap

    std::priority_queue
*/

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    // Creation (Default is Max-Heap)
    priority_queue<int> pq;

    // Push elements (Order doesn't matter)
    pq.push(10);
    pq.push(50); // 50 is the biggest, it bubbles to the top
    pq.push(20);

    // Process
    while (!pq.empty()) 
    {
        cout << pq.top() << " "; // Output: 50 20 10
        pq.pop();
    }
    
    return 0;
}