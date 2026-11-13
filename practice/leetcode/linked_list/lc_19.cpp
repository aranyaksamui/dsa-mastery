
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
    int count = 0;
public:
    ListNode* removeNode(ListNode* node)
    {
        if (node == nullptr)
            return nullptr;

        node->next = removeNode(node->next);
        
        count--;
        if (count == 0)
            return node->next;

        return node;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == nullptr && n == 1) return nullptr;

        count = n;

        ListNode dummy(-1);
        dummy.next = head;

        removeNode(&dummy);

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