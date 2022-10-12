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
nodetype *deleteHead(nodetype *head)
{
    nodetype *ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
nodetype *deleteAtIndex(nodetype *head,int index){
    nodetype *ptr = head;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    nodetype *q=ptr->next;
    ptr->next=q->next;
    free(q);
    return head;
}
nodetype *deleteEnd(nodetype *head)
{
    nodetype *ptr = head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    nodetype *q=ptr->next;
    ptr->next=NULL;
    free(q);
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
    third->next = NULL;

    third->data = 6;
    third->next = fourth;

    fourth->data =46;
    fourth->next =NULL;
    traverse(head);
    /*head=deleteHead(head);
    traverse(head);
    head=deleteAtIndex(head,2);
    traverse(head);*/
    head=deleteEnd(head);
    traverse(head);
    return 0;
}