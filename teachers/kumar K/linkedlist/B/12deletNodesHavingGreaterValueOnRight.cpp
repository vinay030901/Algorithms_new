/*
Given a singly linked list, remove all the nodes which have a greater value on their right side.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60*/
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

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    ListNode *RemoveNodes(ListNode *head)
    {
        head = reverse(head);
        int mx = head->val;
        ListNode *ans = new ListNode(head->val);
        ListNode *start = ans;
        head = head->next;
        while (head)
        {
            if (head->val >= mx)
            {
                ans->next = new ListNode(head->val);
                ans = ans->next;
                mx = head->val;
            }
            head = head->next;
        }
        ans = reverse(start);
        return ans;
    }
};