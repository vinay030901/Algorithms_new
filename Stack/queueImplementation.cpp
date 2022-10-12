#include<bits/stdc++.h>
using namespace std;
#define max 10
void push(int *arr,int ele,int &top)
{
    if(top==max-1)
    {
        cout<<"stack overflow\n";
        return;
    }
    arr[++top]=ele;
    return;
}
void display(int *arr,int top)
{
    if(top==-1)
    {
        cout<<"no element to display\n";
    }
    else
    {
        for(int i=0;i<=top;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
void pop(int *arr,int &top)
{
    if(top==-1)
    {
        cout<<"stack underflow\n";
        return;
    }
    cout<<"the popped element is: "<<arr[top]<<"\n";
    top--;
}
void peek(int *arr,int top)
{
    if(top==-1)
    {
        cout<<"no element to shown\n";
        return;
    }
    cout<<"the peek element is: "<<arr[top]<<"\n";
}
int main()
{
    int arr[max];
    int top=-1;
    display(arr,top);
    push(arr,2,top);
    push(arr,4,top);
    push(arr,-2,top);
    push(arr,9,top);
    display(arr,top);
    pop(arr,top);
    peek(arr,top);
    display(arr,top);
}