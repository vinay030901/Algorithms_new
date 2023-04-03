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
int middle(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int mid = len / 2;
    while (mid--)
    {
        temp = temp->next;
    }
    return temp->val;
}
int middle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return -1;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
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
    ListNode *reverse = Middle(head);
    cout << "reverse of list using 2N solution: ";
    cout << reverse->val << " ";
    ListNode *reverse1 = Middle1(head);
    cout << "\nreverse of list using 2N solution: ";
    cout << reverse1->val << " ";
}