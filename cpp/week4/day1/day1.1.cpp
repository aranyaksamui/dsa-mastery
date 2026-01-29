// Using structs (Structures) with linked lists

#include <iostream>

using namespace std;

struct ListNode
{
    int val;            // Value
    ListNode* next;     // Address of the next node of type ListNode

    ListNode(int x) : val(x), next(nullptr) {};     // Constructor
};

int main()
{
    // Creating two lists in the heap and storing the address of both the heap in stack
    ListNode* head = new ListNode(10);
    ListNode* second = new ListNode(20);

    // Linking the second ListNode to the next of first ListNode (head->next stored in the heap)
    head->next = second;

    // Traversing
    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

    return 0;
}