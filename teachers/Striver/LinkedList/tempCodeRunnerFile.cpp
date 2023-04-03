#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==0) return head;
    // calculating the length
    ListNode *temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    k=k%length;
    ListNode *start=head;
    ListNode *partOne=head;
    for(int i=1;i<length-k;i++)
        partOne=partOne->next;
    ListNode *partTwo=partOne->next;
    partOne->next=NULL;
    ListNode *mid=partTwo;
    while(partTwo->next!=NULL)
        partTwo=partTwo->next;
    partTwo->next=start;
    return mid;
}
int main()
{
    ListNode *head = new ListNode();
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    cout << "list before: ";

    ListNode *t = head;
    while (t != NULL)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "new list: ";