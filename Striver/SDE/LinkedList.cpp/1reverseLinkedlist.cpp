// Given the head of a singly linked list, reverse the list, and return the reversed list
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
ListNode *reverseUsingDummy(ListNode *head)
{
    ListNode *dummy=NULL,*nex=NULL;
    while(head!=NULL)
    {
        nex=head->next;
        head->next=dummy;
        dummy=head;
        head=nex;
    }
    return dummy;
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
    ListNode *head = new ListNode(4);
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
    ListNode *reverse = reverseUsingDummy(head);
    print(reverse);
}