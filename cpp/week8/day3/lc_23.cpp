// 23. Merge k Sorted Lists

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
    ListNode* createNode(int val)
    {
        return new ListNode(val);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (ListNode* head : lists)
        {
            ListNode* temp = head;

            while (temp != nullptr)
            {
                minHeap.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode dummy(-1);
        ListNode* tempHead = &dummy;

        while (!minHeap.empty())
        {
            if (tempHead->next == nullptr) tempHead->next = createNode(minHeap.top());
            minHeap.pop();
            tempHead = tempHead->next;
        }

        ListNode* head = &dummy;
        return head->next;
    }    

    void solve()
    {
        // My test case code
        ListNode* third1 = new ListNode(5);
        ListNode* second1 = new ListNode(4, third1);
        ListNode* head1 = new ListNode(1, second1);
        
        ListNode* third2 = new ListNode(4);
        ListNode* second2 = new ListNode(3, third2);
        ListNode* head2 = new ListNode(1, second2);
        
        ListNode* second3 = new ListNode(6);
        ListNode* head3 = new ListNode(2, second3);

        vector<ListNode*> lists = {head1, head2, head3};

        ListNode* head = mergeKLists(lists);

        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
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