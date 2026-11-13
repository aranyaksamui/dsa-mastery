/*
    LeetCode: 19. Remove Nth Node From End of List (Two pointers)
*/

#include <bits/stdc++.h>

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // Create a dummy node first before the head
        ListNode dummy(-1);
        dummy.next = head;

        // First assign slow and fast pointer to dummy node
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move the fast pointer exactly n + 1 steps
        for (int i = 0; i <= n; i++) fast = fast->next;

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Reassign the slow->next node to slow->next->next and delete the nth node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        // Reassign head
        head = dummy.next;
        return head;
    }

    void solve()
    {
        // My test case code
        
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