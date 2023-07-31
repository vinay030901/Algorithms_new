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
ListNode *swapPairs(ListNode *head)
{
    ListNode *ans = new ListNode();
    ans->next = head;
    ListNode *pre = ans;
    ListNode *cur, *nex;
    while (pre->next && pre->next->next)
    {
        cur = pre->next;
        nex = cur->next;
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
        pre = cur;
    }
    return ans->next;
}