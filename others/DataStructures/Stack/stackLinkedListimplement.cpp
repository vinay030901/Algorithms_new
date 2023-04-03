#include<bits/stdc++.h>
using namespace std;
typedef struct nodetype
{
    int data;
    struct nodetype *next;
}node;
node *push(node *hd,int val)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr->data=val;
    ptr->next=hd;
    hd=ptr;
    return hd;
}
node *pop(node *hd)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr=hd;
    cout<<"the popped element is: "<<ptr->data<<"\n";
    hd=hd->next;
    free(ptr);
    return hd;
}
void display(node *hd)
{
    while(hd!=NULL)
    {
        cout<<hd->data<<" ";
        hd=hd->next;
    }
    cout<<"\n";
}

int main()
{
    node *hd=NULL;
    hd=push(hd,24);
    hd=push(hd,30);
    hd=push(hd,9);
    hd=push(hd,4);
    display(hd);
    /*hd=push(hd,24);
    hd=push(hd,30);
    hd=push(hd,9);
    hd=push(hd,4);*/
    hd=pop(hd);
    display(hd);
}