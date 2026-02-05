// Dummy node

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* returnDummyNode(ListNode* head)
{
    // Declaring a dummy node in the stack
    ListNode dummy(-1);

    // Storing the dummy node's address for modification and attaching it to the head
    ListNode* headOfTheList = &dummy;
    headOfTheList->next = head;

    // Pointing and updating to the actual head of the list
    headOfTheList = headOfTheList->next;

    return headOfTheList;
}

int main()
{
    ListNode* fifth = new ListNode(5);
    ListNode* fourth = new ListNode(4, fifth);
    ListNode* third = new ListNode(3, fourth);
    ListNode* second = new ListNode(2, third);
    ListNode* head = new ListNode(1, second);

    returnDummyNode(head);

    return 0;
}