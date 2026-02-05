// C++ stack

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // Declaring a stack
    stack<int> st;

    // Pushing (inserting) values to stack
    st.push(10);    // First to be inserted
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);    // Last to be inserted

    while (!st.empty())
    {
        // Get the top
        cout << st.top() << endl;
        // Pop the last element
        st.pop();
    }

    if (st.empty()) cout << "Stack is empty" << endl;

    return 0;
}