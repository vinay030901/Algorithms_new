/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.*/

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
ListNode *sort(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val > l2->val)
        std::swap(l1, l2);
    ListNode *res = l1;
    while (l1 && l2)
    {
        ListNode *temp = NULL;
        while (l1 && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        std::swap(l1, l2);
    }
    return res;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // the naive to do this problem is by going over all the lists one by one, then sorting them
    // sorting will take O(n) time and list are k, so time complexity is O(n*k*k) here
    if (lists.size() == 1)
        return lists[0];
    ListNode *pre = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        pre = sort(pre, lists[i]);
    }
    return pre;
}

// the second solution uses heap data structure, here we need to put the first element of all the linkedlist into the heap
// then the smallest one will be at the top of the min heap, we will take it out and push the next element in that linkedlist into it
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    auto comp = [&](ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> mn(comp);
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
            mn.push(lists[i]);
    }
    ListNode *res = new ListNode(-1);
    ListNode *ans = res;
    while (!mn.empty())
    {
        ListNode *cur = mn.top();
        mn.pop();
        if (cur->next)
            mn.push(cur->next);
        res->next = cur;
        res = res->next;
    }
    res->next = NULL;
    return ans->next;
}

// we can use divide and conquer approach for this process
// instead of merging them one by one, we will merge like merge sort where we break the array and then merge them
// like we have 4 lists, then we merge first 2 and last 2 together, then we merge the resultant two lists
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->val > l2->val)
        std::swap(l1, l2);
    ListNode *res = l1;
    while (l1 && l2)
    {
        ListNode *temp = NULL;
        while (l1 && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        std::swap(l1, l2);
    }
    return res;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    if (lists.size() == 1)
        return lists[0];

    int n = lists.size() - 1;
    while (n > 0)
    {
        int i = 0, j = n;
        while (i < j)
        {
            lists[i] = merge(lists[i], lists[j]);
            i++;
            j--;
            if (i >= j)
                n = j;
        }
    }
    return lists[0];
}
int main()
{
}