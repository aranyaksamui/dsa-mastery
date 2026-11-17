/*
    LeetCode: 25. Reverse Nodes in k-Group
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

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // Count the no. of nodes
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }

        // If k > no. of nodes return head
        if (k > n) return head;

        // Create a dummy node
        ListNode dummy(-1);
        dummy.next = head;

        // Calculate remaining and multiple of k
        int rem = n % k;
        int cover = n - rem;
        
        // Some helpfull pointers for tracking and start the reversal in k groups
        ListNode* prev = &dummy;        // The previous node
        ListNode* curr = dummy.next;    // The current node
        ListNode* next = nullptr;       // The next node
        ListNode* groupPrev = prev;     // The last node of the previous group
        ListNode* groupTail = curr;     // The first node (before reversal) and the last node (after reversal) of the group
        for (int i = 0; i < cover; i = i + k)
        {
            // Capture the tail before reversal
            groupTail = groupPrev->next;
            prev = nullptr;

            int step = i;
            while (step < i + k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                
                step++;
            }

            // Stitch previous tail with new head (prev)
            groupPrev->next = prev;
            
            // Stitch current tail to start of the next unreversed group
            groupTail->next = curr;

            // Advance groupPrev to the tail of the group we just finished
            groupPrev = groupTail;
        }

        head = dummy.next;
        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* fifth = new ListNode(5);
        ListNode* fourth = new ListNode(4, fifth);
        ListNode* third = new ListNode(3, fourth);
        ListNode* second = new ListNode(2, third);
        ListNode* head = new ListNode(1, second);
        int k = 2;

        ListNode* temp = reverseKGroup(head, k);
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