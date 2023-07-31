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
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val > l2->val)
        swap(l1, l2);
    ListNode *res = l1;
    while (l1 && l2)
    {
        ListNode *temp = NULL;
        while (l1 && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    int j = lists.size() - 1;
    while (j > 0)
    {
        int i = 0;
        while (i < j)
        {
            lists[i] = merge(lists[i], lists[j]);
            i++;
            j--;
        }
    }
    return lists[0];
}