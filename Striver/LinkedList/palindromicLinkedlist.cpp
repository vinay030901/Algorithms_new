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
    ListNode *dummy = NULL;
    ListNode *cur = head;
    while (cur != NULL)
    {
        ListNode *nex = cur->next;
        cur->next = dummy;
        dummy = cur;
        cur = nex;
    }
    return dummy;
}
bool isPalindrome(ListNode *head)
{
    ListNode *temp = head, *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (slow->val != temp->val)
            return false;
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}