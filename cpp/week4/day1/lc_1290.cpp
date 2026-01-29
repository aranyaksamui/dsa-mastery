// 1290. Convert Binary Number in a Linked List to Integer

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

// Solution Class (Like LeetCode)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        ListNode* temp = head;
        int ans = 0;

        while (temp != nullptr)
        {
            ans = ans * 2 + temp->val;
            temp = temp->next;
        }

        return ans;
    }

    void solve()
    {
        // My test case code
        ListNode* third = new ListNode(1);
        ListNode* second = new ListNode(0, third);
        ListNode* head = new ListNode(1, second);

        cout << getDecimalValue(head) << endl;

        delete head;
        delete second;
        delete third;

        // ListNode* head = new ListNode(0);

        // cout << getDecimalValue(head) << endl;

        // delete head;
        
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