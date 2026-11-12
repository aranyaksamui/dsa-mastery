/*
    LeetCode: 92. Reverse Linked List II
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

// This function speeds up input/output operations
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (!head || left == right) return head;

        // Create a dummy node to before the head itself
        ListNode dummy(0, nullptr);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Traverse the list until before left
        for (int i = 1; i < left; i++)
            prev = prev->next;
        
        ListNode* start = prev->next;       // Start is the node at position left
        ListNode* curr = start;             // Tracks current node while reversing
        ListNode* revPrev = nullptr;        // Tracks previous node while reversing
        ListNode* next = nullptr;           // Tracks next node while reversing
        
        // Loop until right - left + 1 and do the reversal
        for (int i = 0; i <= right - left; i++)
        {
            next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        prev->next = revPrev;               // Stitch the next position of left - 1 node to the new left
        start->next = curr;                 // Stitch the new new of right to right + 1 node

        head = dummy.next;
        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* fourth = new ListNode(5);
        ListNode* third = new ListNode(4, fourth);
        ListNode* second = new ListNode(3, third);
        ListNode* first = new ListNode(2, second);
        ListNode* head = new ListNode(1, first);

        int left = 2;
        int right = 4;

        ListNode* temp = reverseBetween(head, left, right);

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