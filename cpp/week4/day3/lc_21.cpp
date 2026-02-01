// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else if (temp1->val > temp2->val)
            {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }
        if (temp1 == nullptr) tail->next = temp2;
        else if (temp2 == nullptr) tail->next = temp1;

        ListNode* head = &dummy;
        head = head->next;

        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* l1third = new ListNode(4);
        ListNode* l1second = new ListNode(2, l1third);
        ListNode* l1head = new ListNode(1, l1second);

        ListNode* l2third = new ListNode(4);
        ListNode* l2second = new ListNode(3, l2third);
        ListNode* l2head = new ListNode(1, l2second);

        ListNode* temp = mergeTwoLists(l1head, l2head);
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