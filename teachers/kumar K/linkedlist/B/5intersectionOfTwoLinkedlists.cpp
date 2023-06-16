/*
Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with its own memory the original lists should not be changed.
Note: The linked list elements are not necessarily distinct.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40*/
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
    ListNode *findIntersection(ListNode *head1, ListNode *head2)
    {
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        while (head1 || head2)
        {
            if (head1->val == head2->val)
            {
                temp->next = new ListNode(head1->val);
                head1 = head1->next;
                head2 = head2->next;
                temp = temp->next;
            }
            else if (head1->val < head2->val)
                head1 = head1->next;
            else
                head2 = head2->next;
        }
        return ans->next;
    }
};