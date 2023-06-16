
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution
{
public:
    ListNode *reverseDLL(ListNode *head)
    {
        ListNode *pre = NULL;
        while (head)
        {
            ListNode *nex = head->next;
            head->next = pre;
            head->prev = nex;
            pre = head;
            head = nex;
        }
        return pre;
    }
};