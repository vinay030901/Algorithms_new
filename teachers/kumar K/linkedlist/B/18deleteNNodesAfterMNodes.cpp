/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6

Output:
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.*/
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
    void linkdelete(ListNode *head, int M, int N)
    {
        // Add code here
        ListNode *temp = head;
        int m = M, n = N;
        while (temp)
        {
            for (int i = 1; i < M; i++)
                if (temp)
                    temp = temp->next;
            if (!temp)
                break;
            ListNode *temp2 = temp->next;
            for (int j = 0; j < N; j++)
                if (temp2)
                    temp2 = temp2->next;
            temp->next = temp2;
            temp = temp2;
        }
    }
};