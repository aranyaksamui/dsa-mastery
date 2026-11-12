
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
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while (curr != nullptr)
        {
            // Store the next
            next = curr->next;
            // Reverse the current
            curr->next = prev;
            // Move the previous pointer to current
            prev = curr;
            // Move the current pointer to next
            curr = next;
        }

        head = prev;

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

        reverseList(head);
        
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