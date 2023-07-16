/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Explanation:
The first 4 elements 1,2,2,4 are reversed first
and then the next 4 elements 5,6,7,8. Hence, the
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Explanation:
The first 3 elements are 1,2,3 are reversed
first and then elements 4,5 are reversed.Hence,
the resultant linked list is 3->2->1->5->4.*/
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
    ListNode *rev(ListNode *cur)
    {
        ListNode *prev = NULL;
        while (cur)
        {
            ListNode *nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL || k == 1)
            return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy, *nex = dummy, *pre = dummy;
        int length = 0;
        while (cur->next != NULL)
        {
            length++;
            cur = cur->next;
        }
        while (length >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                // we are making 2-1-3 from 1-2-3
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            length -= k;
            pre = cur;
        }
        cur->next = rev(cur->next);
        return dummy->next;
    }
};