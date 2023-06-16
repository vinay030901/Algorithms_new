/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

Example 1:

Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.*/
/*
Idea

I traverse the list in groups where the sizes are in the increasing order of natural numbers.
Whenever a group with even length is encountered, that group is reversed using the reverse function and I proceed with processing the next group.
The solution involves several pointers which track the current group’s head, tail and the next group’s head.*/
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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *prev = temp;
        for (int len = 1; len < 1e5 && head; len++)
        {
            ListNode *tail = head, *nextHead;
            int j = 1;
            while (j < len && tail && tail->next)
            {
                tail = tail->next;
                j++;
            }
            nextHead = tail->next;
            if (j % 2 == 1)
            {
                prev = tail;
                head = nextHead;
            }
            else
            {
                tail->next = NULL;
                prev->next = reverse(head);
                prev = head;
                head->next = nextHead;
                head = nextHead;
            }
        }
        return temp->next;
    }
};