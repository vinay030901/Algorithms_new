/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/
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
// first way is to create a new linkedlist and traverse both linkedlist together and add element using it
// second way is that we will not take extra space, here we will traverse the list1 and when we find another element 
// in list2, we will 
ListNode *SortTwoList(ListNode *list1, ListNode *list2)
{
    // first put all the values in the array and then sort the values, the put it another list and return that list
    vector<int> ans;
    if (!list1 && !list2)
    {
        return NULL;
    }
    if (!list1)
        return list2;
    else if (!list2)
        return list1;
    while (list1 != NULL)
    {
        ans.push_back(list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        ans.push_back(list2->val);
        list2 = list2->next;
    }
    sort(ans.begin(), ans.end());
    ListNode *head = new ListNode(ans[0]);
    ListNode *temp = head;
    for (int i = 1; i < ans.size(); i++)
    {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }
    return head;
}
ListNode *SortTwoList(ListNode *list1, ListNode *list2)
{
    // in this approach,we created a new linkedlist using the two list
    if (!list1)
        return list2;
    else if (!list2)
        return list1;
    ListNode *temp = new ListNode;
    ListNode *curr = temp;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            temp->next = new ListNode(list1->val);
            list1 = list1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = new ListNode(list2->val);
            list2 = list2->next;
            temp = temp->next;
        }
        if (list1 == NULL)
            temp->next = list2;
        if (list2 == NULL)
            temp->next = list1;
    }
    return curr->next;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //here we are doing it in constant space
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    // first of all we will start from l1 and connect all the nodes to l1, if the l2 value is less, then 
    // we will swap the lists and again do the same process, we will use a temp variable for this
    if (l1->val > l2->val)
        std::swap(l1, l2);
    ListNode *res = l1;
    while (l1 != NULL && l2 != NULL)
    {
        ListNode *temp = NULL;
        while (l1 != NULL && l1->val <= l2->val)// l1 is lesser than l2
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;// when l2 is less, connect temp to l2 and then swap the lists, that way temp will connected to l1
        std::swap(l1, l2);
    }
    return res;
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
    ListNode *sort = SortTwoList(head,temp);
    print(sort);
}

ListNode *merge(ListNode *l1, ListNode * l2)
{
    if(!l1) return l2;
    else if(!l2) return l1;
    if(l1->val<=l2->val)
    swap(l1, l2);
    ListNode *res=l1;
    while(l1 && l2)
    {
        ListNode *temp=NULL;
        while(l1 && l1->val<=l2->val)
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return res;
}