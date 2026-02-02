// 83. Remove Duplicates from Sorted List

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

// Definition for singly-linked list for Linked List problems.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This function speeds up input/output operations
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Solution Class (Like LeetCode)
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy(-101);
        ListNode* curr = &dummy;
        curr->next = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next != nullptr ? curr->next->next : nullptr;
                delete temp;
            }
            else curr = curr->next;
        }

        ListNode* list = &dummy;
        return list->next;
    }

    void solve()
    {
        // My test case code
        ListNode* fifth = new ListNode(3);
        ListNode* fourth = new ListNode(3, fifth);
        ListNode* third = new ListNode(2, fourth);
        ListNode* second = new ListNode(1, third);
        ListNode* head = new ListNode(1, second);

        ListNode* temp = deleteDuplicates(head);
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        delete head;
        delete second;
        delete third;
        delete fourth;
        delete fifth;

        cout << endl << "System ready." << endl;
    }
};

int main()
{
    fast_io();
    Solution sol;
    sol.solve();
    return 0;
}