#include<bits/stdc++.h>
using namespace std;
#define max 10
void push(int *arr,int ele,int &front,int &rear)
{
    if((rear+1)%max==front)
    {
        cout<<"no element can be inserted\n";
        return;
    }
    else if(front==-1)
    front=0;
    rear=(rear+1)%max;
    arr[rear]=ele;
}
void display(int *arr,int front,int rear)
{
    if(front==-1)
    {
        cout<<"no element to display\n";
    }
    else
    {
       int t=front;
       do
       {
           cout<<arr[t]<<" ";
           t=(t+1)%max;
            //cout<<arr[t]<<" ";
       }while(t!=rear+1);
       cout<<endl;
    }
}
void pop(int *arr,int &front,int &rear)
{
    if(front==-1)
    {
        cout<<"nothing to pop\n";
        return;
    }
    cout<<"the popped element is: "<<arr[front]<<"\n";
    if(front==rear)
    front=rear=-1;      
    else
    {
        front=(front+1)%max;
    }
}
void peek(int *arr,int front)
{
    if(front==-1)
    {
        cout<<"no element to shown\n";
        return;
    }
    cout<<"the peek element is: "<<arr[front]<<"\n";
}
int main()
{
    int arr[max];
    int rear=-1,front=-1;
    push(arr,2,front,rear);
    push(arr,4,front,rear);
    push(arr,-2,front,rear);
    push(arr,9,front,rear);
    display(arr,front,rear);
    pop(arr,front,rear);
    peek(arr,front);
    display(arr,front,rear);
}