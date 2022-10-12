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
    ListNode *temp = head;
    int length = 0;
    // here we first calculate the length of the linkedlist
    // then use this length to find the value of n from start of the list
    // then we traverse the list and delete that node from start
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if (length == n)
    {
        head = head->next;
        return head;
    }
    temp = head;
    int tr = length - n - 1;
    for (int i = 0; i < tr; i++)
    {
        temp = temp->next;
    }
    ListNode *node = temp->next;
    temp->next = temp->next->next;
    // delete(node);
    return head;
}

ListNode *RemoveNthFromEnd2(ListNode *head, int n)
{
    // here we will do this in single traversal
    // what we will be doing is using fast pointer and slow pointer 
    // at first we will reach the n value using the fast pointer
    // then we will take the slow pointer and fast, and move them together till fast reaches the end, the point at 
    // which slow pointer is now, we have to delete the next node from it, we will then do it

    ListNode *start=new ListNode();// start is the variable whose next is head, so it helps us to initialise the 
    // fast and slow node, and helps in edge cases too
    start->next=head;
    ListNode *fast=start;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }
    ListNode *slow=start;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next =slow->next->next;
    return start->next;
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
    cout<<endl;
    ListNode *remove1 = RemoveNthFromEnd2(head, pos);
    print(remove1);
}