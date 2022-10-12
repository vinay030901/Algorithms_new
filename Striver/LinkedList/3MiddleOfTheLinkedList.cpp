//Given the head of a singly linked list, reverse the list, and return the reversed list
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// first way- find the length, reach the middle
// second way, use the frog tortoise approach
ListNode *Middle(ListNode *head)
{
    int length=0;
    // in this appraoch, we will simply traverse the list and find the length, calculate the mid and then again
    // travel till mid and return mid
    ListNode *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    int mid=length/2;
    temp=head;
    for(int i=0;i<mid;i++)
        temp=temp->next;
    return temp;
}
ListNode *Middle1(ListNode *head)
{
    // in this appraoch, we will use hare tortoise method, here we will use fast node and slow node, fast node will 
    // always be the double of slow node, so we will travel 1 with slow and 2 with fast
    // if fast becomes null, we will return slow as middle
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void print(ListNode *head)
{
    ListNode *temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}
int main()
{
    ListNode *head = new ListNode(4);
    ListNode *temp=head;
    int n,a;
    cout<<"enter the number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        temp->next=new ListNode(a);
        temp=temp->next;
    }
    ListNode *reverse=Middle(head);
    cout<<"reverse of list using 2N solution: ";
    cout<<reverse->val<<" ";
    ListNode *reverse1=Middle1(head);
    cout<<"\nreverse of list using 2N solution: ";
    cout<<reverse1->val<<" ";
}