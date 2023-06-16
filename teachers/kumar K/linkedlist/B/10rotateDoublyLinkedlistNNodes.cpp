/*
Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution
{
public:
    ListNode *rotateDouble(ListNode *head, int n)
    {
        n--;
        ListNode *temp = head, *first = head;
        while (n--)
        {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        temp = head;
        head->prev = NULL;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = first;
        first->prev = temp;
        return head;
    }
};