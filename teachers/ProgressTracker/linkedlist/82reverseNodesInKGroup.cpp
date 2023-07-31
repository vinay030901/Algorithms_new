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
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    int times = len / k;
    ListNode *pre = new ListNode();
    pre->next = head;
    ListNode *ans = pre, *cur, *nex;
    for (int i = 0; i < times; i++)
    {
        cur = pre->next;
        nex = cur->next;
        for (int j = 1; j < k; j++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
    }
    return ans->next;
}