/*
Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.
Example 1:
Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
Example 2:
Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5*/
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
    void deleteNode(ListNode **head, int key)
    {

        // Your code goes here
        ListNode *slow = *head, *fast = (*head)->next;
        while (fast)
        {
            if (fast->val == key)
                break;
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
    }

    /* Function to reverse the linked list */
    void reverse(ListNode **head)
    {

        // Your code goes here
        if (!(*head)->next)
            return;
        ListNode *cur = (*head)->next, *pre = *head;
        while (cur != (*head))
        {
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        cur->next = pre;
        (*head) = pre;
    }
};
