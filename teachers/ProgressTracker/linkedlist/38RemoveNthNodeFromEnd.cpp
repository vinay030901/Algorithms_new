#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int value) : val(value), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next){};
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *slow = start, *fast = start;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
}