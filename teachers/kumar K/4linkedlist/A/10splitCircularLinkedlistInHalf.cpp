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
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void splitList(ListNode *head, ListNode **h1, ListNode **h2)
    {
        // your code goes here
        ListNode *mid = getMiddle(head);
        *h1 = head;
        (*h2) = mid->next;
        ListNode *temp = (*h2);
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = *h2;
        mid->next = *h1;
    }
};