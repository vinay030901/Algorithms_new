#include<bits/stdc++.h>
using namespace std;
typedef struct nodetype {
    int data;
    struct nodetype *next;
    struct nodetype *prev;
}node;
node *mid=NULL;
int cnt=0;
node *push(node*hd,int ele)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr->data=ele;
    if(hd==NULL)
    {
        hd=ptr;
        mid=ptr;
        ptr->prev=NULL;
    }
    else
    {
        ptr->prev=NULL;
        ptr->next=hd;
        hd->prev=ptr;
        hd=ptr;
    }
    cnt++;
    if(cnt%2==0)
    mid=mid->prev;
    return hd;
}
node *pop(node *hd)
{
    if(cnt==0)
    cout<<"stack underflow\n";
    else
    {
        node *ptr;
        ptr=(node*)malloc(sizeof(node*));
        ptr=hd;
        hd=hd->next;
        free(ptr);
        if(hd!=NULL)
        hd->prev=NULL;
    }
    cnt--;
    if(cnt%2==1)
    mid=mid->next;
    return hd;
}
int middle(){
    if(cnt==0)
    {
        cout<<"stack is empty\n";
        return -1;
    }
    else
    return mid->data;
}
void display(node *hd){
    node *ptr;
    ptr=(node*)malloc(sizeof(node*));
    ptr=hd;
    for(int i=0;i<cnt;i++)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main()
{
    node *hd=NULL;
    hd=push(hd,24);
    hd=push(hd,24);
    hd=push(hd,30);
    hd=push(hd,9);
    hd=push(hd,4);
    hd=pop(hd);
    hd=pop(hd);
    
    display(hd);
    cout<<middle();
}