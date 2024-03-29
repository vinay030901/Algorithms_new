/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n*/
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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *it = dummy;
    ListNode *prevIt = NULL;
    for (int i = 0; i < left; i++)
    {
        prevIt = it;
        it = it->next;
    }
    ListNode *itR = it;
    ListNode *prevR = prevIt;
    while (left <= right)
    {
        ListNode *n = itR->next;
        itR->next = prevR;
        prevR = itR;
        itR = n;
        left++;
    }
    prevIt->next = prevR;
    it->next = itR;
    return dummy->next;
}
int main()
{
    ListNode *head = new ListNode();
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    cout << "list before: ";

    ListNode *t = head;
    while (t != NULL)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "new list: ";
    ListNode *p = reverseBetween(head->next, 2, 4);
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}