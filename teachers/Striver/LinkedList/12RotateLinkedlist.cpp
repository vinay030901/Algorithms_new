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
ListNode *rotateRight(ListNode *head, int k)
{
    // to rotate, we take an external linkedlist, we traverse till k, made a new linkedlist from node next to k
    // then we add the linkedlist from start to it.
    // this approach uses external space for rotating
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // calculating the length
    ListNode *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    k = k % length;
    if (k == 0)
        return head;
    ListNode *start = head;
    ListNode *partOne = head;
    for (int i = 1; i < length - k; i++)
        partOne = partOne->next;
    ListNode *partTwo = partOne->next;
    partOne->next = NULL;
    ListNode *mid = partTwo;
    while (partTwo->next != NULL)
        partTwo = partTwo->next;
    partTwo->next = start;
    return mid;
}
ListNode *rotateRight2(ListNode *head, int k)
{
    // here the method is inplace because we aren't using any external space.
    // first we calculate length and while doing that, we reach the end, and then we connect end to head
    // then we reach the node at (length-k)
    // so next node we will be the start, therefore we make next as head and we make this node null.
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // calculating the length
    ListNode *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    k = k % length;
    temp->next = head;
    k = length - k;
    while (k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
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
    ListNode *p = rotateRight2(head->next, 2);
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}