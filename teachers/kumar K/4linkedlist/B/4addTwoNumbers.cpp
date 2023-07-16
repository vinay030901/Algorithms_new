/*
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).*/
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
        ListNode *pre = NULL;
        while (head)
        {
            ListNode *nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }
    struct ListNode *addTwoLists(ListNode *first, ListNode *second)
    {
        // code here
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        int carry = 0;
        first = reverse(first);

        second = reverse(second);
        // cout<<first->val<<" "<<second->val;
        while (first || second || carry)
        {
            int sum = 0;
            if (first)
            {
                sum += first->val;
                first = first->next;
            }
            if (second)
            {
                sum += second->val;
                second = second->next;
            }
            if (carry)
                sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = node;
        }
        return reverse(ans->next);
    }
};
