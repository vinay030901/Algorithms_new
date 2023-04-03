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
void traverse(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    cout << "enter the length of the list" << endl;
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ListNode *t = new ListNode(a);
        temp->next = t;
        temp = temp->next;
    }
    traverse(head->next);
}
