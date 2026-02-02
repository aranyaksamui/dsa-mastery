// 876. Middle of the Linked List

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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            if (fast->next->next != nullptr) fast = fast->next->next;
            else fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }

    void solve()
    {
        // My test case code
        ListNode* fifth = new ListNode(5);
        ListNode* fourth = new ListNode(4, fifth);
        ListNode* third = new ListNode(3, fourth);
        ListNode* second = new ListNode(2, third);
        ListNode* head = new ListNode(1, second);

        cout << middleNode(head)->val << endl;

        delete head;
        delete second;
        delete third;
        delete fourth;
        delete fifth;

        // ListNode* sixth = new ListNode(6);
        // ListNode* fifth = new ListNode(5, sixth);
        // ListNode* fourth = new ListNode(4, fifth);
        // ListNode* third = new ListNode(3, fourth);
        // ListNode* second = new ListNode(2, third);
        // ListNode* head = new ListNode(1, second);

        cout << middleNode(head)->val << endl;

        // delete head;
        // delete second;
        // delete third;
        // delete fourth;
        // delete fifth;
        // delete sixth;

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