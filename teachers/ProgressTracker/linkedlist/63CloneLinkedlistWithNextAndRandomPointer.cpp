/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value
set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes
in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in
the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and
y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of
[val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.





Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    // here we used unordered_map and just copied the values from head to our new list
    // first we made the new list copied the values only, while next and random remains NULL.
    // then we again started from head and copied the next and random values
    unordered_map<Node *, Node *> mp;
    Node *temp = head;
    while (temp)
    {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}

Node *copyRandomList(Node *head)
{
    // here we will follow three steps:
    // first: make copy of each node and link together side by side to the real list
    // 1->1'->2->2'->3->3'
    // 1' will be between 1 and 2 here
    Node *iter = head;
    Node *front = head;
    while (iter != NULL)
    {
        front = iter->next;
        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;
        iter=front;
    }

    // in second round- we will change the value of the random pointer in our linkedlist
    // we will copy the random value in our main list to our copied values
    iter=head;
    while(iter != NULL)
    {
        if(iter->random!=NULL)
        {
            iter->next->random=iter->random->next;
        }
        iter=iter->next->next;
    }

    // so we have copied the random values now 
    // now we restore the list and extract the copoied list 
    iter=head;
    Node *temp=new Node(0);
    Node *copy=temp;
    while(iter!=NULL)
    {
        front=iter->next->next;

        // extract the copy
        copy->next=iter->next;

        // restore the original list
        iter->next=front;

        // move forward
        copy= copy->next;
        iter=front;
    }
    return temp->next;
}
int main()
{
}