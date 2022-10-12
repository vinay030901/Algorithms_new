#include<bits/stdc++.h>
using namespace std;
typedef struct nodetype
{
    int data;
    struct nodetype *next;
}node;
node *push(node *front,node *rear,int ele)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr->data=ele;
    if(rear==NULL)
    {
        cout<<"front value changed\n";
        front=ptr;
        rear=ptr;}
    else
    {
        rear->next=ptr;
        rear=ptr;
        rear->next=NULL;
    }
    return rear;
}
node *pop(node *front)
{
    if(front==NULL)
    {
        cout<<"nothing to pop\n";
        return front;
    }
    node *ptr=NULL;
    ptr=(node*)malloc(sizeof(node*));
    ptr=front;
    front=front->next;
    free(ptr);
    return front;
}
void display(node *front)
{
    if(front==NULL)
    {
        cout<<"nothing to display\n";
        return;
    }
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr=front;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void peek(node *front)
{
    if(front==NULL)
    {
        cout<<"nothing to display\n";
        return;
    }
    cout<<"peek element: "<<front->data<<endl;

}
int main()
{
    node *hd=NULL,*tl=NULL;
    tl=push(hd,tl,24);
    if(hd==NULL)
    hd=tl;
    tl=push(hd,tl,30);
    if(hd==NULL)
    hd=tl;
    tl=push(hd,tl,9);
    if(hd==NULL)
    hd=tl;
    tl=push(hd,tl,4);
    if(hd==NULL)
    hd=tl;
    peek(hd);
    display(hd);
    /*tl=push(hd,tl,24);
    tl=push(hd,tl,30);
    tl=push(hd,tl,9);
    tl=push(hd,tl,4);*/
    hd=pop(hd);
    peek(hd);
    display(hd);
}