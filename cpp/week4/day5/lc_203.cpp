// 203. Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        curr->next = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->next->val == val && curr->next->next != nullptr)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else if (curr->next->val == val && curr->next->next == nullptr) curr->next = nullptr;
            else curr = curr->next;
        }

        ListNode* list = &dummy;
        return list->next;
    }

    void solve()
    {
        // My test case code
        // ListNode* seventh = new ListNode(6);
        // ListNode* sixth = new ListNode(5, seventh);
        // ListNode* fifth = new ListNode(4, sixth);
        // ListNode* fourth = new ListNode(3, fifth);
        // ListNode* third = new ListNode(6, fourth);
        // ListNode* second = new ListNode(2, third);
        // ListNode* head = new ListNode(1, second);

        // int val = 6;
        // ListNode* temp = removeElements(head, val);
        // while (temp != nullptr)
        // {
        //     cout << temp->val << " ";
        //     temp = temp->next;
        // }

        // delete head;
        // delete second;
        // delete third;
        // delete fourth;
        // delete fifth;
        // delete sixth;
        // delete seventh;

        ListNode* fourth = new ListNode(7);
        ListNode* third = new ListNode(7, fourth);
        ListNode* second = new ListNode(7, third);
        ListNode* head = new ListNode(7, second);

        int val = 7;
        ListNode* temp = removeElements(head, val);
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        delete head;
        delete second;
        delete third;
        delete fourth;
        
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