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
ListNode *reverse(ListNode *head)
{
    ListNode *pre = NULL, *cur = head;
    while (cur)
    {
        ListNode *nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
bool isPalindrome(ListNode *head)
{
    if (!head->next)
        return true;
    ListNode *slow = head, *fast = head, *temp = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (temp->val != slow->val)
            return false;
        temp = temp->next;
        slow = slow->next;
    }
    return true;
}