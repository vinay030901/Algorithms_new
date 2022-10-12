/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode *temp=new ListNode();
    ListNode *head=temp;
    while(l1!=NULL || l2!=NULL || carry!=0)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ListNode *node=new ListNode(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return head->next;
}
void print(ListNode *head)
{
    ListNode *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}
int main()
{
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *temp=l1;
    int n,a;
    cout<<"enter the number of nodes in first list: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ListNode *node=new ListNode(a);
        temp->next=node;
        temp=temp->next;
    }
    cout<<"enter the number of nodes in second list: ";
    cin>>n;
    ListNode *temp1=l2;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ListNode *node=new ListNode(a);
        temp1->next=node;
        temp1=temp1->next;
    }
    ListNode *sum=addTwoNumbers(l1,l2);
    print(sum->next);
}