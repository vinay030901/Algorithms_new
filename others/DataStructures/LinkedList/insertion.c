#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}nodetype;
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node *insertatFirst(nodetype *head,int data){
    nodetype *ptr=(nodetype *)malloc(sizeof(nodetype));
    ptr->data = data;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node *insertatIndex(nodetype *head,int data,int index){
    nodetype *ptr=(nodetype *)malloc(sizeof(nodetype));
    nodetype *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node *insertatEnd(nodetype *head,int data){
    nodetype *ptr=(nodetype *)malloc(sizeof(nodetype));
    nodetype *p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data =46;
    fourth->next =NULL;

    traverse(head);
    head=insertatFirst(head,56);
    traverse(head);
    head=insertatIndex(head,21,2);
    traverse(head);
    head=insertatEnd(head,90);
    traverse(head);
    return 0;
}