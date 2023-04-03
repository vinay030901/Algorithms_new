// Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
// there are two ways to do this problem
// 1. find the length of the list, then using this, reach the point of n-k
// 2. another method is putting one pointer at 0 and other at k, traverse them, when the second pointer will reach the end, we will delete that node
ListNode *RemoveNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    if(len==n){
        head=head->next;
        return head;
    }
    n = len - n;
    temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    ListNode *toDel = temp->next;
    temp->next = temp->next->next;
    return head;
}

ListNode *RemoveNthFromEnd2(ListNode *head, int n)
{
    ListNode *slow=new ListNode(-1);
    slow->next = head;
    ListNode *fast=head;
    for(int i=0; i<n; i++) fast=fast->next;
    while(fast!= NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int n, a;
    cout << "enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        temp->next = new ListNode(a);
        temp = temp->next;
    }
    cout << "enter the position from end: ";
    int pos = 0;
    cin >> pos;
    ListNode *remove = RemoveNthFromEnd(head, pos);
    print(remove);
    cout << endl;
    ListNode *remove1 = RemoveNthFromEnd2(head, pos);
    print(remove1);
}