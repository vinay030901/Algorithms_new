#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void add(ListNode *head, int &one)
    {
        if (!head)
            return;
        add(head->next, one);
        if (one == 1)
        {
            if (head->val == 9)
            {
                head->val = 0;
            }
            else
            {
                head->val = head->val + one;
                one = 0;
            }
        }
    }
    ListNode *addOne(ListNode *head)
    {
        // Your Code here
        // return head of list after adding one
        int one = 1;
        add(head, one);
        if (one == 1)
        {
            ListNode *temp = new ListNode(1);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};