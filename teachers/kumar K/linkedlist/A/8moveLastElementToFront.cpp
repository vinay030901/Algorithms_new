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
    void findFirstNode(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        ListNode *first = temp->next;
        temp->next = NULL;
        first->next = head;
        head = first;
    }
};