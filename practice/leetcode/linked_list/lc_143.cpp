/*
    LeetCode: 143. Reorder List
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
public:
    void reorderList(ListNode* head)
    {
        if (head->next == nullptr) return;

        // Push nodes to stack to track nodes from end to start
        // Count the no. of nodes
        ListNode* temp = head;
        stack<ListNode*> nodeStack;
        int n = 0;
        while (temp != nullptr)
        {
            nodeStack.push(temp);
            temp = temp->next;
            n++;
        }

        // Create a dummy node to sew the entire list as required and keep track of it's head
        ListNode dummy(-1);

        ListNode* curr = head;      // Track the node start to end
        ListNode* end = &dummy;     // Sew the nodes at the end of the dummy
        int st = 0;                 // Start position pointer
        int en = n - 1;             // End position pointer
        while (st <= en)
        {
            // Store and pop the nodes from the stack (tracking end to start)
            ListNode* top = nodeStack.top();
            nodeStack.pop();

            // Save the next node of current to not loose the list made track start to end
            ListNode* nextCurr = curr->next;

            // Handle odd no. of nodes
            if (st == en && curr->val == top->val)
            {
                end->next = curr;
                end = end->next;
                break;
            }

            // Sewing the end list
            end->next = curr;
            end = end->next;
            end->next = top;
            end = end->next;

            // Iterating current using the saved pointer
            curr = nextCurr;

            // Iterate positions
            st++;
            en--;
        }

        // Cut off the old tail pointer to prevent cycle
        end->next = nullptr;
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