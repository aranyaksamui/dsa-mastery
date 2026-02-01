// 141. Linked List Cycle

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
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution Class (Like LeetCode)
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) return false;

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        
        return false;
    }

    void solve()
    {
        // My test case code
        // ListNode* fourth;
        // ListNode* third;
        // ListNode* second;
        // ListNode* head;
        
        // fourth = new ListNode(-4);
        // third = new ListNode(0, fourth);
        // second = new ListNode(2, third);
        // fourth->next = second;
        // head = new ListNode(3, second);

        // cout << hasCycle(head) << endl;
        
        ListNode* second;
        ListNode* head;
        
        second = new ListNode(2);
        head = new ListNode(1, second);
        second->next = head;

        cout << hasCycle(head) << endl;
        
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