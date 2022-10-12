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
void traverse(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *slow = start;
    ListNode *fast = start;
    for (int i = 1; i <= n; i++)
        fast = fast->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
}
int main()
{
}