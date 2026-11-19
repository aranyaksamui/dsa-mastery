/*
    LeetCode: 82. Remove Duplicates from Sorted List II
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
        if (head == nullptr) return nullptr;
        
        if (head->next == nullptr) return head;

        // Count the frequency of numbers
        unordered_map<int, int> freq;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            freq[temp->val]++;
            temp = temp->next;
        }

        // Create a dummy node
        ListNode dummy(-1);
        dummy.next = head;

        // Filter out and delete duplicate nodes
        ListNode* slow = &dummy;    // Hold the previous pointer just before a duplicate
        ListNode* fast = head;      // Skip the duplicates
        while (fast != nullptr)
        {
            // Check if current node has duplicates (>1 frequency)
            if (freq[fast->val] > 1)
            {
                fast = fast->next;
                continue;
            }

            slow->next = fast;
            slow = fast;
            fast = fast->next;
        }

        // Sew the slow pointer to fast to prevent unhandled duplicates at the end
        slow->next = fast;

        head = dummy.next;
        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* fourth = new ListNode(5);
        ListNode* third = new ListNode(4, fourth);
        ListNode* third1 = new ListNode(4, third);
        ListNode* second = new ListNode(3, third1);
        ListNode* second1 = new ListNode(3, second);
        ListNode* first = new ListNode(2, second1);
        ListNode* head = new ListNode(1, first);

        ListNode* temp = deleteDuplicates(head);

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