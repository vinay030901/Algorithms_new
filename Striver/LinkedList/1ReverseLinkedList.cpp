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
    // so what we are doing in this process is using a dummy node and next node
    ListNode *dummy = NULL, *next = NULL;
    // we will initialise the dummy node and next node, dummy node act like previous and therefore it has a NULL value
    // and the head will point it later, while next node point at the next of head
    while (head != NULL)
    {
        next = head->next;  // so next will point to the next of the head
        head->next = dummy; // then head will point at at the previous node, so head will point at NULL at the start,
        // but later it point to the previous node, so turning it or reversing it
        dummy = head; // then dummy will take the place of head and head will will placed further, that is next of it
        head = next;
    
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