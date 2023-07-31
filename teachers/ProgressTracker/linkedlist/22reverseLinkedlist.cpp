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
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    while (head)
    {
        ListNode *nex = head->next;
        head->next = prev;
        prev = head;
        head = nex;
    }
    return prev;
}