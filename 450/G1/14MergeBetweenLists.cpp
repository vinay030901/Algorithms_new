#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    // the approach is simple, we will move to the node at a, connect that node to the list2 head
    // then we move to node at b+1, and traverse at the end of linkedlist
    // connect the end of list2 to b+1th, return the head of list1
    ListNode *temp=list1;
    for(int i=1;i<a;i++)
        temp=temp->next;
    ListNode *ath=temp;
    for(int i=a;i<=b+1;i++)
        temp=temp->next;
    ListNode *bth=temp;
    ListNode *h2=list2;
    ath->next=h2;
    while(list2->next!=NULL)
        list2=list2->next;
    list2->next=bth;
    return list1;
}
int main()
{

}