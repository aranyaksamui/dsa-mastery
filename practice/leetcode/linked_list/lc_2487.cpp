/*
    LeetCode: 2487. Remove Nodes From Linked List
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <stack>
#include <queue>

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        
        return head;
    }

    ListNode* removeNodes(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        
        if (head->next == nullptr) return head;

        // First reverse the list
        head = reverseList(head);
        
        // Traversed the reversed list
        ListNode* curr = head;
        int maxVal = curr->val;
        while(curr != nullptr)
        {
            if (curr->next == nullptr)
            {
                curr = curr->next;
            }
            // Remove the next node with less value than current and rewrite it with next of next
            else if (curr->next->val < maxVal)
            {
                curr->next = curr->next->next;
            }
            // If next node value is bigger or equal we have new max keep it
            else
            {
                maxVal = curr->next->val;
                curr = curr->next;
            }
        }

        // Reverse the updated list again
        head = reverseList(head);

        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* fourth = new ListNode(8);
        ListNode* third = new ListNode(3, fourth);
        ListNode* second = new ListNode(13, third);
        ListNode* first = new ListNode(2, second);
        ListNode* head = new ListNode(5, first);

        ListNode* temp = removeNodes(head);

        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        
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