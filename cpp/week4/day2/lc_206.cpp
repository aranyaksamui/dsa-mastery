// 206. Reverse Linked List

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;

        while (currNode != nullptr)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;

        return head;
    }

    void solve()
    {
        // My test case code
        ListNode* fifth = new ListNode(5);
        ListNode* fourth = new ListNode(4, fifth);
        ListNode* third = new ListNode(3, fourth);
        ListNode* second = new ListNode(2, third);
        ListNode* head = new ListNode(1, second);

        ListNode* temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << endl;
            temp = temp->next;
        }
        cout << endl;
        temp = reverseList(head);
        while (temp != nullptr)
        {
            cout << temp->val << endl;
            temp = temp->next;
        }

        delete head;
        delete second;
        delete third;
        delete fourth;
        delete fifth;




        // ListNode* second = new ListNode(2);
        // ListNode* head = new ListNode(1, second);

        // delete head;
        // delete second;


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