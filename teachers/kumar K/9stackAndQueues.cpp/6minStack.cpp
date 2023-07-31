/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    struct Node
    {
        int val, mn;
        Node *next;
        Node(int val, int mn, Node *next) : val(val), mn(mn), next(next) {}
    };
    MinStack()
    {
    }
    Node *head = new Node(INT_MAX, INT_MAX, NULL);
    void push(int val)
    {
        Node *temp = new Node(val, min(val, head->mn), head);
        head = temp;
    }

    void pop()
    {
        head = head->next;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->mn;
    }
};
int main()
{

    return 0;
}