
/*
    LeetCode: 19. Remove Nth Node From End of List (Recursive)
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
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
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
private:
    // Maintain a count to track the nth node from last
    int count = 0;
public:
    ListNode* removeNode(ListNode* node)
    {
        // Base case: Return nullptr if we reach the next of last node
        if (node == nullptr)
            return nullptr;

        // Progressive case: pass node of next and while returning connect it back to next of current
        node->next = removeNode(node->next);
        
        // Reduce count till and if it's 0 then we reached the nth node from last, return node->next instead of current node to delete the link for the previous node
        count--;
        if (count == 0)
            return node->next;

        // In normal case just return the current node for next of previous
        return node;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == nullptr && n == 1) return nullptr;

        // Assign a copy of n
        count = n;

        // Create a dummy node
        ListNode dummy(-1);
        dummy.next = head;

        // Start traversing the list till last with a dummy node before head
        removeNode(&dummy);

        // Return next node of dummy as head
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
        int n = 2;

        ListNode* temp = removeNthFromEnd(head, n);
        
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