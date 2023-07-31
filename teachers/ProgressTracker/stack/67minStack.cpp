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