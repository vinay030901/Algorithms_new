/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer. For more clearity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *list1, Node *list2)
{
    // merge technique is used from temp
    Node *temp = new Node(0);
    Node *res = temp;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            temp->bottom = list1;
            list1 = list1->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = list2;
            list2 = list2->bottom;
            temp = temp->bottom;
        }
    }
    if (list1)
        temp->bottom = list1;
    if (list2)
        temp->bottom = list2;
    return res->bottom;
}
Node *flatten(Node *head)
{
    // we will use merge sort technique for this task
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flatten(head->next); // recursion is first used to reach the end of lists and then merge from there
    head = merge(head, head->next);
    return head;
}