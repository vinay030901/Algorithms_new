/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.


Example 1:

Input:
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers
so they appear first and 17,15,9 are odd
numbers that appear later.

Example 2:

Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number.
So ne need for modification.*/
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
ListNode *divide(int N, ListNode *head)
{
    // code here
    ListNode *even = new ListNode(-1);
    ListNode *odd = new ListNode(-1);
    ListNode *etail = even;
    ListNode *otail = odd;
    while (head)
    {
        if (head->val % 2 == 0)
        {
            etail->next = head;
            etail = etail->next;
        }
        else
        {
            otail->next = head;
            otail = otail->next;
        }
        head = head->next;
    }
    otail->next = NULL;
    etail->next = odd->next;
    return even->next;
}