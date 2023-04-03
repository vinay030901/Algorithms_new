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
void sortList(ListNode *l1, ListNode *l2)
{
    vector<int> arr;
    while (l1 != NULL)
    {
        arr.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        arr.push_back(l2->val);
        l2 = l2->next;
    }
    ListNode *ans = new ListNode[arr[0]];
    for (int i = 1; i < arr.size(); i++)
    {
        ans->next = new ListNode(arr[i]);
        ans = ans->next;
    }
}
ListNode* sortList(ListNode *l1, ListNode *l2)
{
    ListNode *res = l1;
    if (l1->val < l2->val)
        std::swap(l1, l2);

    while (l1 != NULL && l2 != NULL)
    {
        ListNode *temp;
        while (l1 != NULL && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        std::swap(l1, l2);
    }
    return res;
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